/**
 * Copyright (c) 2000-2013 Liferay, Inc. All rights reserved.
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2.1 of the License, or (at your option)
 * any later version.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
 * details.
 */

package com.liferay.mobile.android.http;

import com.liferay.mobile.android.exception.ServerException;
import com.liferay.mobile.android.service.ServiceContext;

import java.io.IOException;

import org.apache.http.Header;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.HttpStatus;
import org.apache.http.StatusLine;
import org.apache.http.auth.UsernamePasswordCredentials;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.auth.BasicScheme;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.util.EntityUtils;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

/**
 * @author Bruno Farache
 */
public class HttpUtil {

	public static HttpClient getClient(ServiceContext context) {
		DefaultHttpClient client = new DefaultHttpClient();

		HttpConnectionParams.setConnectionTimeout(
			client.getParams(), context.getConnectionTimeout());

		return client;
	}

	public static PortalVersion getPortalVersion(ServiceContext context) {
		return getPortalVersion(context.getServer());
	}

	public static PortalVersion getPortalVersion(String url) {
		try {
			HttpClient client = new DefaultHttpClient();

			HttpGet get = new HttpGet(url);

			HttpResponse response = client.execute(get);

			Header portalHeader = response.getFirstHeader("Liferay-Portal");

			if (portalHeader == null) {
				return PortalVersion.UNKNOWN;
			}

			String portalField = portalHeader.getValue();

			int indexOfBuild = portalField.indexOf("Build");

			if (indexOfBuild == -1) {
				return PortalVersion.UNKNOWN;
			}
			else {
				String buildNumber = portalField.substring(
					indexOfBuild + 6, indexOfBuild + 10);

				buildNumber = buildNumber.replaceAll("0*$", "");

				return PortalVersion.getValue(Integer.valueOf(buildNumber));
			}
		}
		catch (Exception e) {
			return PortalVersion.UNKNOWN;
		}
	}

	public static HttpPost getPost(ServiceContext context) {
		HttpPost post = new HttpPost(getUrl(context));

		UsernamePasswordCredentials credentials =
			new UsernamePasswordCredentials(
				context.getUsername(), context.getPassword());

		Header authorization = BasicScheme.authenticate(
			credentials, "UTF-8", false);

		post.addHeader(authorization);

		return post;
	}

	public static String getResponseString(HttpResponse response)
		throws IOException {

		HttpEntity entity = response.getEntity();

		if (entity == null) {
			return null;
		}

		return EntityUtils.toString(entity);
	}

	public static String getUrl(ServiceContext context) {
		StringBuilder sb = new StringBuilder();

		sb.append(context.getServer());
		sb.append("/api/jsonws/invoke");

		return sb.toString();
	}

	public static JSONArray post(ServiceContext context, JSONArray commands)
		throws Exception {

		HttpClient client = getClient(context);
		HttpPost post = getPost(context);

		post.setEntity(new StringEntity(commands.toString()));

		HttpResponse response = client.execute(post);;

		String json = HttpUtil.getResponseString(response);

		return handleResponse(response, json);
	}

	public static JSONArray post(ServiceContext context, JSONObject command)
		throws Exception {

		JSONArray commands = new JSONArray();

		commands.put(command);

		return post(context, commands);
	}

	protected static JSONArray handleResponse(
			HttpResponse response, String json)
		throws ServerException {

		StatusLine status = response.getStatusLine();

		if (status.getStatusCode() == HttpStatus.SC_UNAUTHORIZED) {
			throw new ServerException("Authentication failed.");
		}

		try {
			if (json != null) {
				if (json.startsWith("{")) {
					JSONObject jsonObj = new JSONObject(json);

					if (jsonObj.has("exception")) {
						String message = jsonObj.getString("exception");

						throw new ServerException(message);
					}
					else {
						throw new ServerException(
							"Unexpected return type: " + json.toString());
					}
				}
				else if (json.startsWith("[")) {
					return new JSONArray(json);
				}
			}
		}
		catch (JSONException je) {
			throw new ServerException(je);
		}

		return null;
	}

}