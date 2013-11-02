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

#import "DLFileShortcutService_v62.h"

/**
 * author Bruno Farache
 */
@implementation DLFileShortcutService_v62

- (void)deleteFileShortcut:(long)fileShortcutId {
	NSDictionary *_params = @{
		@"fileShortcutId": @(fileShortcutId)
	};

	NSDictionary *_command = @{@"/dlfileshortcut/delete-file-shortcut": _params};

	[self.session invoke:_command];
}

- (NSDictionary *)getFileShortcut:(long)fileShortcutId {
	NSDictionary *_params = @{
		@"fileShortcutId": @(fileShortcutId)
	};

	NSDictionary *_command = @{@"/dlfileshortcut/get-file-shortcut": _params};

	return (NSDictionary *)[self.session invoke:_command];
}

- (NSDictionary *)updateFileShortcut:(long)fileShortcutId folderId:(long)folderId toFileEntryId:(long)toFileEntryId serviceContext:(NSDictionary *)serviceContext {
	NSDictionary *_params = @{
		@"fileShortcutId": @(fileShortcutId),
		@"folderId": @(folderId),
		@"toFileEntryId": @(toFileEntryId),
		@"serviceContext": serviceContext
	};

	NSDictionary *_command = @{@"/dlfileshortcut/update-file-shortcut": _params};

	return (NSDictionary *)[self.session invoke:_command];
}

- (NSDictionary *)addFileShortcut:(long)groupId folderId:(long)folderId toFileEntryId:(long)toFileEntryId serviceContext:(NSDictionary *)serviceContext {
	NSDictionary *_params = @{
		@"groupId": @(groupId),
		@"folderId": @(folderId),
		@"toFileEntryId": @(toFileEntryId),
		@"serviceContext": serviceContext
	};

	NSDictionary *_command = @{@"/dlfileshortcut/add-file-shortcut": _params};

	return (NSDictionary *)[self.session invoke:_command];
}

@end