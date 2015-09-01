// Credit to LUNI for most of this.

#pragma once

#include <iostream>
#include <BitStream.h>

using namespace RakNet;
using namespace std;

// RemoteConnection IDs
enum RemoteConnection : unsigned char
{
	SERVER = 0,
	AUTH,
	CHAT,
	UNKOWN,
	WORLD,
	CLIENT
};

// IDs for all servers
enum ServerPacketID : unsigned char
{
	MSG_SERVER_VERSION_CONFIRM = 0,
	MSG_SERVER_DISCONNECT_NOTIFY,
	MSG_SERVER_GENERAL_NOTIFY,
};

enum ChatPacketID : unsigned char
{
	MSG_CHAT_LOGIN_SESSION_NOTIFY = 0x00,
	MSG_CHAT_GENERAL_CHAT_MESSAGE = 0x01,
	MSG_CHAT_PRIVATE_CHAT_MESSAGE = 0x02,
	MSG_CHAT_USER_CHANNEL_CHAT_MESSAGE = 0x03,
	MSG_CHAT_WORLD_DISCONNECT_REQUEST = 0x04,
	MSG_CHAT_WORLD_PROXIMITY_RESPONSE = 0x05,
	MSG_CHAT_WORLD_PARCEL_RESPONSE = 0x06,
	MSG_CHAT_ADD_FRIEND_REQUEST = 0x07,
	MSG_CHAT_ADD_FRIEND_RESPONSE = 0x08,
	MSG_CHAT_REMOVE_FRIEND = 0x09,
	MSG_CHAT_GET_FRIENDS_LIST = 0x0a,
	MSG_CHAT_ADD_IGNORE = 0x0b,
	MSG_CHAT_REMOVE_IGNORE = 0x0c,
	MSG_CHAT_GET_IGNORE_LIST = 0x0d,
	MSG_CHAT_TEAM_MISSED_INVITE_CHECK = 0x0e,
	MSG_CHAT_TEAM_INVITE = 0x0f,
	MSG_CHAT_TEAM_INVITE_RESPONSE = 0x10,
	MSG_CHAT_TEAM_KICK = 0x11,
	MSG_CHAT_TEAM_LEAVE = 0x12,
	MSG_CHAT_TEAM_SET_LOOT = 0x13,
	MSG_CHAT_TEAM_SET_LEADER = 0x14,
	MSG_CHAT_TEAM_GET_STATUS = 0x15,
	MSG_CHAT_GUILD_CREATE = 0x16,
	MSG_CHAT_GUILD_INVITE = 0x17,
	MSG_CHAT_GUILD_INVITE_RESPONSE = 0x18,
	MSG_CHAT_GUILD_LEAVE = 0x19,
	MSG_CHAT_GUILD_KICK = 0x1a,
	MSG_CHAT_GUILD_GET_STATUS = 0x1b,
	MSG_CHAT_GUILD_GET_ALL = 0x1c,
	MSG_CHAT_SHOW_ALL = 0x1d,
	MSG_CHAT_BLUEPRINT_MODERATED = 0x1e,
	MSG_CHAT_BLUEPRINT_MODEL_READY = 0x1f,
	MSG_CHAT_PROPERTY_READY_FOR_APPROVAL = 0x20,
	MSG_CHAT_PROPERTY_MODERATION_CHANGED = 0x21,
	MSG_CHAT_PROPERTY_BUILDMODE_CHANGED = 0x22,
	MSG_CHAT_PROPERTY_BUILDMODE_CHANGED_REPORT = 0x23,
	MSG_CHAT_MAIL = 0x24,
	MSG_CHAT_WORLD_INSTANCE_LOCATION_REQUEST = 0x25,
	MSG_CHAT_REPUTATION_UPDATE = 0x26,
	MSG_CHAT_SEND_CANNED_TEXT = 0x27,
	MSG_CHAT_GMLEVEL_UPDATE = 0x28,
	MSG_CHAT_CHARACTER_NAME_CHANGE_REQUEST = 0x29,
	MSG_CHAT_CSR_REQUEST = 0x2a,
	MSG_CHAT_CSR_REPLY = 0x2b,
	MSG_CHAT_GM_KICK = 0x2c,
	MSG_CHAT_GM_ANNOUNCE = 0x2d,
	MSG_CHAT_GM_MUTE = 0x2e,
	MSG_CHAT_ACTIVITY_UPDATE = 0x2f,
	MSG_CHAT_WORLD_ROUTE_PACKET = 0x30,
	MSG_CHAT_GET_ZONE_POPULATIONS = 0x31,
	MSG_CHAT_REQUEST_MINIMUM_CHAT_MODE = 0x32,
	MSG_CHAT_REQUEST_MINIMUM_CHAT_MODE_PRIVATE = 0x33,
	MSG_CHAT_MATCH_REQUEST = 0x34,
	MSG_CHAT_UGCMANIFEST_REPORT_MISSING_FILE = 0x35,
	MSG_CHAT_UGCMANIFEST_REPORT_DONE_FILE = 0x36,
	MSG_CHAT_UGCMANIFEST_REPORT_DONE_BLUEPRINT = 0x37,
	MSG_CHAT_UGCC_REQUEST = 0x38,
	MSG_CHAT_WHO = 0x39,
	MSG_CHAT_WORLD_PLAYERS_PET_MODERATED_ACKNOWLEDGE = 0x3a,
	MSG_CHAT_ACHIEVEMENT_NOTIFY = 0x3b,
	MSG_CHAT_GM_CLOSE_PRIVATE_CHAT_WINDOW = 0x3c,
	MSG_CHAT_UNEXPECTED_DISCONNECT = 0x3d,
	MSG_CHAT_PLAYER_READY = 0x3e,
	MSG_CHAT_GET_DONATION_TOTAL = 0x3f,
	MSG_CHAT_UPDATE_DONATION = 0x40,
	MSG_CHAT_PRG_CSR_COMMAND = 0x41,
	MSG_CHAT_HEARTBEAT_REQUEST_FROM_WORLD = 0x42,
	MSG_CHAT_UPDATE_FREE_TRIAL_STATUS = 0x43
};

enum ClientAuthPacketID : unsigned char
{
	MSG_AUTH_LOGIN_REQUEST = 0x00,
	MSG_AUTH_LOGOUT_REQUEST = 0x01,
	MSG_AUTH_CREATE_NEW_ACCOUNT_REQUEST = 0x02,
	MSG_AUTH_LEGOINTERFACE_AUTH_RESPONSE = 0x03,
	MSG_AUTH_SESSIONKEY_RECEIVED_CONFIRM = 0x04,
	MSG_AUTH_RUNTIME_CONFIG = 0x05
};

enum ClientWorldPacketID : unsigned char
{
	MSG_WORLD_CLIENT_VALIDATION = 0x01,
	MSG_WORLD_CLIENT_CHARACTER_LIST_REQUEST = 0x02,
	MSG_WORLD_CLIENT_CHARACTER_CREATE_REQUEST = 0x03,
	MSG_WORLD_CLIENT_CHARACTER_DELETE_REQUEST = 0x04,
	MSG_WORLD_CLIENT_CHARACTER_RENAME_REQUEST = 0x07,
	MSG_WORLD_CLIENT_HAPPY_FLOWER_MODE_NOTIFY = 0x08,
	MSG_WORLD_CLIENT_SLASH_RELOAD_MAP = 0x09,
	MSG_WORLD_CLIENT_SLASH_PUSH_MAP_REQUEST = 0x0a,
	MSG_WORLD_CLIENT_SLASH_PUSH_MAP = 0x0b,
	MSG_WORLD_CLIENT_SLASH_PULL_MAP = 0x0c,
	MSG_WORLD_CLIENT_LOCK_MAP_REQUEST = 0x0d,
	MSG_WORLD_CLIENT_GENERAL_CHAT_MESSAGE = 0x0e,
	MSG_WORLD_CLIENT_HTTP_MONITOR_INFO_REQUEST = 0x0f,
	MSG_WORLD_CLIENT_SLASH_DEBUG_SCRIPTS = 0x10,
	MSG_WORLD_CLIENT_MODELS_CLEAR = 0x11,
	MSG_WORLD_CLIENT_EXHIBIT_INSERT_MODEL = 0x12,
	MSG_WORLD_CLIENT_LEVEL_LOAD_COMPLETE = 0x13,
	MSG_WORLD_CLIENT_TMP_GUILD_CREATE = 0x14,
	MSG_WORLD_CLIENT_ROUTE_PACKET = 0x15,
	MSG_WORLD_CLIENT_POSITION_UPDATE = 0x16,
	MSG_WORLD_CLIENT_MAIL = 0x17,
	MSG_WORLD_CLIENT_WORD_CHECK = 0x18,
	MSG_WORLD_CLIENT_STRING_CHECK = 0x19,
	MSG_WORLD_CLIENT_GET_PLAYERS_IN_ZONE = 0x1a,
	MSG_WORLD_CLIENT_REQUEST_UGC_MANIFEST_INFO = 0x1b,
	MSG_WORLD_CLIENT_BLUEPRINT_GET_ALL_DATA_REQUEST = 0x1c,
	MSG_WORLD_CLIENT_CANCEL_MAP_QUEUE = 0x1d,
	MSG_WORLD_CLIENT_HANDLE_FUNNESS = 0x1e,
	MSG_WORLD_CLIENT_FAKE_PRG_CSR_MESSAGE = 0x1f,
	MSG_WORLD_CLIENT_REQUEST_FREE_TRIAL_REFRESH = 0x20,
	MSG_WORLD_CLIENT_GM_SET_FREE_TRIAL_STATUS = 0x21,
	MSG_WORLD_TOP_5_ISSUES_REQUEST = 0x22,
	MSG_WORLD_UGC_DOWNLOAD_FAILED_T = 0x23,
	MSG_WORLD_UGC_DOWNLOAD_FAILED = 0x78
};

enum WorldServerPacketID : unsigned char
{
	MSG_CLIENT_LOGIN_RESPONSE = 0x00,
	MSG_CLIENT_LOGOUT_RESPONSE = 0x01,
	MSG_CLIENT_LOAD_STATIC_ZONE = 0x02,
	MSG_CLIENT_CREATE_OBJECT = 0x03,
	MSG_CLIENT_CREATE_CHARACTER = 0x04,
	MSG_CLIENT_CREATE_CHARACTER_EXTENDED = 0x05,
	MSG_CLIENT_CHARACTER_LIST_RESPONSE = 0x06,
	MSG_CLIENT_CHARACTER_CREATE_RESPONSE = 0x07,
	MSG_CLIENT_CHARACTER_RENAME_RESPONSE = 0x08,
	MSG_CLIENT_CHAT_CONNECT_RESPONSE = 0x09,
	MSG_CLIENT_AUTH_ACCOUNT_CREATE_RESPONSE = 0x0a,
	MSG_CLIENT_DELETE_CHARACTER_RESPONSE = 0x0b,
	MSG_CLIENT_GAME_MSG = 0x0c,
	MSG_CLIENT_CONNECT_CHAT = 0x0d,
	MSG_CLIENT_TRANSFER_TO_WORLD = 0x0e,
	MSG_CLIENT_IMPENDING_RELOAD_NOTIFY = 0x0f,
	MSG_CLIENT_MAKE_GM_RESPONSE = 0x10,
	MSG_CLIENT_HTTP_MONITOR_INFO_RESPONSE = 0x11,
	MSG_CLIENT_SLASH_PUSH_MAP_RESPONSE = 0x12, // Push map
	MSG_CLIENT_SLASH_PULL_MAP_RESPONSE = 0x13, // Pull map
	MSG_CLIENT_SLASH_LOCK_MAP_RESPONSE = 0x14, // Lock map
	MSG_CLIENT_BLUEPRINT_SAVE_RESPONSE = 0x15,
	MSG_CLIENT_BLUEPRINT_LUP_SAVE_RESPONSE = 0x16,
	MSG_CLIENT_BLUEPRINT_LOAD_RESPONSE_ITEMID = 0x17,
	MSG_CLIENT_BLUEPRINT_GET_ALL_DATA_RESPONSE = 0x18,
	MSG_CLIENT_MODEL_INSTANTIATE_RESPONSE = 0x19,
	MSG_CLIENT_DEBUG_OUTPUT = 0x1a,
	MSG_CLIENT_ADD_FRIEND_REQUEST = 0x1b,
	MSG_CLIENT_ADD_FRIEND_RESPONSE = 0x1c,
	MSG_CLIENT_REMOVE_FRIEND_RESPONSE = 0x1d,
	MSG_CLIENT_GET_FRIENDS_LIST_RESPONSE = 0x1e,
	MSG_CLIENT_UPDATE_FRIEND_NOTIFY = 0x1f,
	MSG_CLIENT_ADD_IGNORE_RESPONSE = 0x20,
	MSG_CLIENT_REMOVE_IGNORE_RESPONSE = 0x21,
	MSG_CLIENT_GET_IGNORE_LIST_RESPONSE = 0x22,
	MSG_CLIENT_TEAM_INVITE = 0x23,
	MSG_CLIENT_TEAM_INVITE_INITIAL_RESPONSE = 0x24,
	MSG_CLIENT_GUILD_CREATE_RESPONSE = 0x25,
	MSG_CLIENT_GUILD_GET_STATUS_RESPONSE = 0x26,
	MSG_CLIENT_GUILD_INVITE = 0x27,
	MSG_CLIENT_GUILD_INVITE_INITIAL_RESPONSE = 0x28,
	MSG_CLIENT_GUILD_INVITE_FINAL_RESPONSE = 0x29,
	MSG_CLIENT_GUILD_INVITE_CONFIRM = 0x2a,
	MSG_CLIENT_GUILD_ADD_PLAYER = 0x2b,
	MSG_CLIENT_GUILD_REMOVE_PLAYER = 0x2c,
	MSG_CLIENT_GUILD_LOGIN_LOGOUT = 0x2d,
	MSG_CLIENT_GUILD_RANK_CHANGE = 0x2e,
	MSG_CLIENT_GUILD_DATA = 0x2f,
	MSG_CLIENT_GUILD_STATUS = 0x30,
	MSG_CLIENT_MAIL = 0x31,
	MSG_CLIENT_DB_PROXY_RESULT = 0x32,
	MSG_CLIENT_SHOW_ALL_RESPONSE = 0x33,
	MSG_CLIENT_WHO_RESPONSE = 0x34,
	MSG_CLIENT_SEND_CANNED_TEXT = 0x35,
	MSG_CLIENT_UPDATE_CHARACTER_NAME = 0x36,
	MSG_CLIENT_SET_NETWORK_SIMULATOR = 0x37,
	MSG_CLIENT_INVALID_CHAT_MESSAGE = 0x38,
	MSG_CLIENT_MINIMUM_CHAT_MODE_RESPONSE = 0x39,
	MSG_CLIENT_MINIMUM_CHAT_MODE_RESPONSE_PRIVATE = 0x3a,
	MSG_CLIENT_CHAT_MODERATION_STRING = 0x3b,
	MSG_CLIENT_UGC_MANIFEST_RESPONSE = 0x3c,
	MSG_CLIENT_IN_LOGIN_QUEUE = 0x3d,
	MSG_CLIENT_SERVER_STATES = 0x3e,
	MSG_CLIENT_GM_CLOSE_TARGET_CHAT_WINDOW = 0x3f,
	MSG_CLIENT_GENERAL_TEXT_FOR_LOCALIZATION = 0x40,
	MSG_CLIENT_UPDATE_FREE_TRIAL_STATUS = 0x41
};

void WriteStringToBitStream(const char* myString, int stringSize, int maxChars, RakNet::BitStream* output);

void CreatePacketHeader(MessageID messageId, unsigned short connectionType, unsigned long internalPacketId, BitStream* output);