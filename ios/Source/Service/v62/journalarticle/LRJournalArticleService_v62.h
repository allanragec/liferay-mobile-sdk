/**
 * Copyright (c) 2000-2014 Liferay, Inc. All rights reserved.
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

#import "LRBaseService.h"

/**
 * @author Bruno Farache
 */
@interface LRJournalArticleService_v62 : LRBaseService

- (NSDictionary *)addArticleWithGroupId:(long long)groupId folderId:(long long)folderId classNameId:(long long)classNameId classPK:(long long)classPK articleId:(NSString *)articleId autoArticleId:(BOOL)autoArticleId titleMap:(NSDictionary *)titleMap descriptionMap:(NSDictionary *)descriptionMap content:(NSString *)content type:(NSString *)type ddmStructureKey:(NSString *)ddmStructureKey ddmTemplateKey:(NSString *)ddmTemplateKey layoutUuid:(NSString *)layoutUuid displayDateMonth:(int)displayDateMonth displayDateDay:(int)displayDateDay displayDateYear:(int)displayDateYear displayDateHour:(int)displayDateHour displayDateMinute:(int)displayDateMinute expirationDateMonth:(int)expirationDateMonth expirationDateDay:(int)expirationDateDay expirationDateYear:(int)expirationDateYear expirationDateHour:(int)expirationDateHour expirationDateMinute:(int)expirationDateMinute neverExpire:(BOOL)neverExpire reviewDateMonth:(int)reviewDateMonth reviewDateDay:(int)reviewDateDay reviewDateYear:(int)reviewDateYear reviewDateHour:(int)reviewDateHour reviewDateMinute:(int)reviewDateMinute neverReview:(BOOL)neverReview indexable:(BOOL)indexable articleURL:(NSString *)articleURL serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (NSDictionary *)addArticleWithGroupId:(long long)groupId folderId:(long long)folderId classNameId:(long long)classNameId classPK:(long long)classPK articleId:(NSString *)articleId autoArticleId:(BOOL)autoArticleId titleMap:(NSDictionary *)titleMap descriptionMap:(NSDictionary *)descriptionMap content:(NSString *)content type:(NSString *)type ddmStructureKey:(NSString *)ddmStructureKey ddmTemplateKey:(NSString *)ddmTemplateKey layoutUuid:(NSString *)layoutUuid displayDateMonth:(int)displayDateMonth displayDateDay:(int)displayDateDay displayDateYear:(int)displayDateYear displayDateHour:(int)displayDateHour displayDateMinute:(int)displayDateMinute expirationDateMonth:(int)expirationDateMonth expirationDateDay:(int)expirationDateDay expirationDateYear:(int)expirationDateYear expirationDateHour:(int)expirationDateHour expirationDateMinute:(int)expirationDateMinute neverExpire:(BOOL)neverExpire reviewDateMonth:(int)reviewDateMonth reviewDateDay:(int)reviewDateDay reviewDateYear:(int)reviewDateYear reviewDateHour:(int)reviewDateHour reviewDateMinute:(int)reviewDateMinute neverReview:(BOOL)neverReview indexable:(BOOL)indexable smallImage:(BOOL)smallImage smallImageURL:(NSString *)smallImageURL smallFile:(LRUploadData *)smallFile images:(NSDictionary *)images articleURL:(NSString *)articleURL serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (NSDictionary *)copyArticleWithGroupId:(long long)groupId oldArticleId:(NSString *)oldArticleId newArticleId:(NSString *)newArticleId autoArticleId:(BOOL)autoArticleId version:(double)version error:(NSError **)error;
- (void)deleteArticleWithGroupId:(long long)groupId articleId:(NSString *)articleId articleURL:(NSString *)articleURL serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (void)deleteArticleWithGroupId:(long long)groupId articleId:(NSString *)articleId version:(double)version articleURL:(NSString *)articleURL serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (void)expireArticleWithGroupId:(long long)groupId articleId:(NSString *)articleId articleURL:(NSString *)articleURL serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (NSDictionary *)expireArticleWithGroupId:(long long)groupId articleId:(NSString *)articleId version:(double)version articleURL:(NSString *)articleURL serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (NSDictionary *)getArticleWithId:(long long)id error:(NSError **)error;
- (NSDictionary *)getArticleWithGroupId:(long long)groupId articleId:(NSString *)articleId error:(NSError **)error;
- (NSDictionary *)getArticleWithGroupId:(long long)groupId articleId:(NSString *)articleId version:(double)version error:(NSError **)error;
- (NSDictionary *)getArticleWithGroupId:(long long)groupId className:(NSString *)className classPK:(long long)classPK error:(NSError **)error;
- (NSDictionary *)getArticleByUrlTitleWithGroupId:(long long)groupId urlTitle:(NSString *)urlTitle error:(NSError **)error;
- (NSString *)getArticleContentWithGroupId:(long long)groupId articleId:(NSString *)articleId languageId:(NSString *)languageId themeDisplay:(LRJSONObjectWrapper *)themeDisplay error:(NSError **)error;
- (NSString *)getArticleContentWithGroupId:(long long)groupId articleId:(NSString *)articleId version:(double)version languageId:(NSString *)languageId themeDisplay:(LRJSONObjectWrapper *)themeDisplay error:(NSError **)error;
- (NSArray *)getArticlesWithGroupId:(long long)groupId folderId:(long long)folderId error:(NSError **)error;
- (NSArray *)getArticlesWithGroupId:(long long)groupId folderId:(long long)folderId start:(int)start end:(int)end obc:(LRJSONObjectWrapper *)obc error:(NSError **)error;
- (NSArray *)getArticlesByArticleIdWithGroupId:(long long)groupId articleId:(NSString *)articleId start:(int)start end:(int)end obc:(LRJSONObjectWrapper *)obc error:(NSError **)error;
- (NSArray *)getArticlesByLayoutUuidWithGroupId:(long long)groupId layoutUuid:(NSString *)layoutUuid error:(NSError **)error;
- (NSArray *)getArticlesByStructureIdWithGroupId:(long long)groupId ddmStructureKey:(NSString *)ddmStructureKey start:(int)start end:(int)end obc:(LRJSONObjectWrapper *)obc error:(NSError **)error;
- (NSArray *)getArticlesByStructureIdWithGroupId:(long long)groupId classNameId:(long long)classNameId ddmStructureKey:(NSString *)ddmStructureKey status:(int)status start:(int)start end:(int)end obc:(LRJSONObjectWrapper *)obc error:(NSError **)error;
- (NSNumber *)getArticlesCountWithGroupId:(long long)groupId folderId:(long long)folderId error:(NSError **)error;
- (NSNumber *)getArticlesCountWithGroupId:(long long)groupId folderId:(long long)folderId status:(int)status error:(NSError **)error;
- (NSNumber *)getArticlesCountByArticleIdWithGroupId:(long long)groupId articleId:(NSString *)articleId error:(NSError **)error;
- (NSNumber *)getArticlesCountByStructureIdWithGroupId:(long long)groupId ddmStructureKey:(NSString *)ddmStructureKey error:(NSError **)error;
- (NSNumber *)getArticlesCountByStructureIdWithGroupId:(long long)groupId classNameId:(long long)classNameId ddmStructureKey:(NSString *)ddmStructureKey status:(int)status error:(NSError **)error;
- (NSDictionary *)getDisplayArticleByUrlTitleWithGroupId:(long long)groupId urlTitle:(NSString *)urlTitle error:(NSError **)error;
- (NSNumber *)getFoldersAndArticlesCountWithGroupId:(long long)groupId folderIds:(NSArray *)folderIds error:(NSError **)error;
- (NSArray *)getGroupArticlesWithGroupId:(long long)groupId userId:(long long)userId rootFolderId:(long long)rootFolderId start:(int)start end:(int)end orderByComparator:(LRJSONObjectWrapper *)orderByComparator error:(NSError **)error;
- (NSArray *)getGroupArticlesWithGroupId:(long long)groupId userId:(long long)userId rootFolderId:(long long)rootFolderId status:(int)status start:(int)start end:(int)end orderByComparator:(LRJSONObjectWrapper *)orderByComparator error:(NSError **)error;
- (NSNumber *)getGroupArticlesCountWithGroupId:(long long)groupId userId:(long long)userId rootFolderId:(long long)rootFolderId error:(NSError **)error;
- (NSNumber *)getGroupArticlesCountWithGroupId:(long long)groupId userId:(long long)userId rootFolderId:(long long)rootFolderId status:(int)status error:(NSError **)error;
- (NSDictionary *)getLatestArticleWithResourcePrimKey:(long long)resourcePrimKey error:(NSError **)error;
- (NSDictionary *)getLatestArticleWithGroupId:(long long)groupId articleId:(NSString *)articleId status:(int)status error:(NSError **)error;
- (NSDictionary *)getLatestArticleWithGroupId:(long long)groupId className:(NSString *)className classPK:(long long)classPK error:(NSError **)error;
- (void)moveArticleWithGroupId:(long long)groupId articleId:(NSString *)articleId newFolderId:(long long)newFolderId error:(NSError **)error;
- (NSDictionary *)moveArticleFromTrashWithGroupId:(long long)groupId articleId:(NSString *)articleId newFolderId:(long long)newFolderId serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (NSDictionary *)moveArticleFromTrashWithGroupId:(long long)groupId resourcePrimKey:(long long)resourcePrimKey newFolderId:(long long)newFolderId serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (NSDictionary *)moveArticleToTrashWithGroupId:(long long)groupId articleId:(NSString *)articleId error:(NSError **)error;
- (void)removeArticleLocaleWithCompanyId:(long long)companyId languageId:(NSString *)languageId error:(NSError **)error;
- (NSDictionary *)removeArticleLocaleWithGroupId:(long long)groupId articleId:(NSString *)articleId version:(double)version languageId:(NSString *)languageId error:(NSError **)error;
- (void)restoreArticleFromTrashWithResourcePrimKey:(long long)resourcePrimKey error:(NSError **)error;
- (void)restoreArticleFromTrashWithGroupId:(long long)groupId articleId:(NSString *)articleId error:(NSError **)error;
- (NSArray *)searchWithCompanyId:(long long)companyId groupId:(long long)groupId folderIds:(NSArray *)folderIds classNameId:(long long)classNameId keywords:(NSString *)keywords version:(LRJSONObjectWrapper *)version type:(NSString *)type ddmStructureKey:(NSString *)ddmStructureKey ddmTemplateKey:(NSString *)ddmTemplateKey displayDateGT:(long long)displayDateGT displayDateLT:(long long)displayDateLT status:(int)status reviewDate:(long long)reviewDate start:(int)start end:(int)end obc:(LRJSONObjectWrapper *)obc error:(NSError **)error;
- (NSArray *)searchWithCompanyId:(long long)companyId groupId:(long long)groupId folderIds:(NSArray *)folderIds classNameId:(long long)classNameId articleId:(NSString *)articleId version:(LRJSONObjectWrapper *)version title:(NSString *)title description:(NSString *)description content:(NSString *)content type:(NSString *)type ddmStructureKey:(NSString *)ddmStructureKey ddmTemplateKey:(NSString *)ddmTemplateKey displayDateGT:(long long)displayDateGT displayDateLT:(long long)displayDateLT status:(int)status reviewDate:(long long)reviewDate andOperator:(BOOL)andOperator start:(int)start end:(int)end obc:(LRJSONObjectWrapper *)obc error:(NSError **)error;
- (NSArray *)searchWithCompanyId:(long long)companyId groupId:(long long)groupId folderIds:(NSArray *)folderIds classNameId:(long long)classNameId articleId:(NSString *)articleId version:(LRJSONObjectWrapper *)version title:(NSString *)title description:(NSString *)description content:(NSString *)content type:(NSString *)type ddmStructureKeys:(NSArray *)ddmStructureKeys ddmTemplateKeys:(NSArray *)ddmTemplateKeys displayDateGT:(long long)displayDateGT displayDateLT:(long long)displayDateLT status:(int)status reviewDate:(long long)reviewDate andOperator:(BOOL)andOperator start:(int)start end:(int)end obc:(LRJSONObjectWrapper *)obc error:(NSError **)error;
- (NSDictionary *)searchWithGroupId:(long long)groupId creatorUserId:(long long)creatorUserId status:(int)status start:(int)start end:(int)end error:(NSError **)error;
- (NSNumber *)searchCountWithCompanyId:(long long)companyId groupId:(long long)groupId folderIds:(NSArray *)folderIds classNameId:(long long)classNameId keywords:(NSString *)keywords version:(LRJSONObjectWrapper *)version type:(NSString *)type ddmStructureKey:(NSString *)ddmStructureKey ddmTemplateKey:(NSString *)ddmTemplateKey displayDateGT:(long long)displayDateGT displayDateLT:(long long)displayDateLT status:(int)status reviewDate:(long long)reviewDate error:(NSError **)error;
- (NSNumber *)searchCountWithCompanyId:(long long)companyId groupId:(long long)groupId folderIds:(NSArray *)folderIds classNameId:(long long)classNameId articleId:(NSString *)articleId version:(LRJSONObjectWrapper *)version title:(NSString *)title description:(NSString *)description content:(NSString *)content type:(NSString *)type ddmStructureKey:(NSString *)ddmStructureKey ddmTemplateKey:(NSString *)ddmTemplateKey displayDateGT:(long long)displayDateGT displayDateLT:(long long)displayDateLT status:(int)status reviewDate:(long long)reviewDate andOperator:(BOOL)andOperator error:(NSError **)error;
- (NSNumber *)searchCountWithCompanyId:(long long)companyId groupId:(long long)groupId folderIds:(NSArray *)folderIds classNameId:(long long)classNameId articleId:(NSString *)articleId version:(LRJSONObjectWrapper *)version title:(NSString *)title description:(NSString *)description content:(NSString *)content type:(NSString *)type ddmStructureKeys:(NSArray *)ddmStructureKeys ddmTemplateKeys:(NSArray *)ddmTemplateKeys displayDateGT:(long long)displayDateGT displayDateLT:(long long)displayDateLT status:(int)status reviewDate:(long long)reviewDate andOperator:(BOOL)andOperator error:(NSError **)error;
- (void)subscribeWithGroupId:(long long)groupId error:(NSError **)error;
- (void)unsubscribeWithGroupId:(long long)groupId error:(NSError **)error;
- (NSDictionary *)updateArticleWithUserId:(long long)userId groupId:(long long)groupId folderId:(long long)folderId articleId:(NSString *)articleId version:(double)version titleMap:(NSDictionary *)titleMap descriptionMap:(NSDictionary *)descriptionMap content:(NSString *)content layoutUuid:(NSString *)layoutUuid serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (NSDictionary *)updateArticleWithGroupId:(long long)groupId folderId:(long long)folderId articleId:(NSString *)articleId version:(double)version titleMap:(NSDictionary *)titleMap descriptionMap:(NSDictionary *)descriptionMap content:(NSString *)content type:(NSString *)type ddmStructureKey:(NSString *)ddmStructureKey ddmTemplateKey:(NSString *)ddmTemplateKey layoutUuid:(NSString *)layoutUuid displayDateMonth:(int)displayDateMonth displayDateDay:(int)displayDateDay displayDateYear:(int)displayDateYear displayDateHour:(int)displayDateHour displayDateMinute:(int)displayDateMinute expirationDateMonth:(int)expirationDateMonth expirationDateDay:(int)expirationDateDay expirationDateYear:(int)expirationDateYear expirationDateHour:(int)expirationDateHour expirationDateMinute:(int)expirationDateMinute neverExpire:(BOOL)neverExpire reviewDateMonth:(int)reviewDateMonth reviewDateDay:(int)reviewDateDay reviewDateYear:(int)reviewDateYear reviewDateHour:(int)reviewDateHour reviewDateMinute:(int)reviewDateMinute neverReview:(BOOL)neverReview indexable:(BOOL)indexable smallImage:(BOOL)smallImage smallImageURL:(NSString *)smallImageURL smallFile:(LRUploadData *)smallFile images:(NSDictionary *)images articleURL:(NSString *)articleURL serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (NSDictionary *)updateArticleWithGroupId:(long long)groupId folderId:(long long)folderId articleId:(NSString *)articleId version:(double)version content:(NSString *)content serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (NSDictionary *)updateArticleTranslationWithGroupId:(long long)groupId articleId:(NSString *)articleId version:(double)version locale:(NSString *)locale title:(NSString *)title description:(NSString *)description content:(NSString *)content images:(NSDictionary *)images error:(NSError **)error;
- (NSDictionary *)updateArticleTranslationWithGroupId:(long long)groupId articleId:(NSString *)articleId version:(double)version locale:(NSString *)locale title:(NSString *)title description:(NSString *)description content:(NSString *)content images:(NSDictionary *)images serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;
- (NSDictionary *)updateContentWithGroupId:(long long)groupId articleId:(NSString *)articleId version:(double)version content:(NSString *)content error:(NSError **)error;
- (NSDictionary *)updateStatusWithGroupId:(long long)groupId articleId:(NSString *)articleId version:(double)version status:(int)status articleURL:(NSString *)articleURL serviceContext:(LRJSONObjectWrapper *)serviceContext error:(NSError **)error;

@end