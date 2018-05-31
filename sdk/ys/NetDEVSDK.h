#ifndef _NETDEV_H_
#define _NETDEV_H_

#ifdef  __cplusplus
extern "C"{
#endif

#ifndef STATIC
    #define STATIC                  static
#endif

#ifndef CONST
    #define CONST                   const
#endif

#ifndef EXTERN
    #define EXTERN                  extern
#endif

#ifndef INLINE
    #define INLINE                  __inline
#endif

#ifndef UNION
    #define UNION                   union
#endif

#ifndef IN
    #define IN
#endif

#ifndef OUT
    #define OUT
#endif

#ifndef INOUT
    #define INOUT
#endif

#ifndef NEWINTERFACE
    #define NEWINTERFACE
#endif

#if defined(WIN32)  /* windows */
#if defined(NETDEV_SDK_DLL)
#define NETDEV_API                  __declspec(dllexport)
#else
#define NETDEV_API                  __declspec(dllimport)
#endif
#else
#define NETDEV_API
#endif

/*  Standard function calling convention */
#ifdef i386
    #ifdef LINUX
        #ifndef STDCALL
        #define STDCALL                 __attribute__((stdcall))__attribute__((visibility ("default")))
        #endif
    #else
        #ifndef STDCALL
        #define STDCALL                 __attribute__((stdcall))
        #endif
    #endif
#else
    #ifdef WIN32
        #ifndef STDCALL
        #define STDCALL                 __stdcall
        #endif
    #else
        #ifdef LINUX
            #ifndef STDCALL
            #define STDCALL                 __attribute__((stdcall))__attribute__((visibility ("default")))
            #endif
        #else
            #ifndef STDCALL
            #define STDCALL
            #endif
        #endif
    #endif
#endif


#ifndef UCHAR_DEF
#define UCHAR_DEF
    typedef unsigned char           UCHAR;
#endif

#ifndef CHAR_DEF
#define CHAR_DEF
    typedef char                    CHAR;
#endif

#ifndef BYTE_DEF
#define BYTE_DEF
    typedef unsigned char           BYTE;
#endif

#ifndef UINT16_DEF
#define UINT16_DEF
    typedef unsigned short          UINT16;
#endif

#ifndef UINT_DEF
#define UINT_DEF
    typedef unsigned int            UINT32;
#endif

#ifndef INT16_DEF
#define INT16_DEF
    typedef  short                  INT16;
#endif

#ifndef INT32_DEF
#define INT32_DEF
    typedef  int                    INT32;
#endif

#ifndef LPVOID_DEF
#define LPVOID_DEF
    typedef void*                   LPVOID;
#endif

#ifndef VOID
#ifndef VOID_DEF
#define VOID_DEF
    typedef void                    VOID;
#endif
#endif

#ifndef INT64_DEF
#define INT64_DEF
    typedef long long               INT64;
#endif

#ifndef BOOL_DEF
#define BOOL_DEF
    #ifndef TARGET_OS_IOS
        typedef int                 BOOL;
    #else
        #import<objc/objc.h>
    #endif
#endif

#ifndef FLOAT
#ifndef VOID_FLOAT
#define VOID_FLOAT
    typedef float                   FLOAT;
#endif
#endif

#ifndef FALSE
    #define FALSE                   0
#endif

#ifndef TRUE
    #define TRUE                    1
#endif

#ifndef WIN32
    typedef LPVOID                 HWND;
#endif

/**********************************   Commonly used numerical macros *************** */

/* ID  Length of stream ID*/
#define NETDEV_STREAM_ID_LEN                    32

/*   Length of filename */
#define NETDEV_FILE_NAME_LEN                    (256u)

/*   Maximum length of username */
#define NETDEV_USER_NAME_LEN                    32

/*   Maximum length of password */
#define NETDEV_PASSWD_LEN                       64

/* ,  Length of password and encrypted passcode for user login */
#define NETDEV_PASSWD_ENCRYPT_LEN               64

/*   Length of resource code string */
#define NETDEV_RES_CODE_LEN                     48

/*   Maximum length of domain name */
#define NETDEV_DOMAIN_LEN                       64

/*   Maximum length of device name */
#define NETDEV_DEVICE_NAME_LEN                  32

/*   Maximum length of path */
#define NETDEV_PATH_LEN_WITHOUT_NAME            64

/* :  Maximum length of path, including filename */
#define NETDEV_PATH_LEN                         128

/* Email  Maximum length of email address */
#define NETDEV_EMAIL_NAME_ADDR                  32

/* Mac  Length of MAC address */
#define NETDEV_MAC_ADDR_LEN                     6

/* gsoapendpoint  Length of endpoint called by gSOAP */
#define NETDEV_ENDPOINT_LEN                     96

/* ID  Maximum length of session ID */
#define NETDEV_SESSION_ID_LEN                   16

/* URL   Maximum length of URL */
#define NETDEV_MAX_URL_LEN                         512

/*   Common length */
#define NETDEV_LEN_4                            4
#define NETDEV_LEN_8                            8
#define NETDEV_LEN_16                           16
#define NETDEV_LEN_32                           32
#define NETDEV_LEN_64                           64
#define NETDEV_LEN_128                          128
#define NETDEV_LEN_132                          132
#define NETDEV_LEN_260                          260
#define NETDEV_LEN_1024                         1024

/* IP   Length of IP address string */
#define NETDEV_IPADDR_STR_MAX_LEN              (64u)

/* IPV4 Length of IPV4 address string */
#define NETDEV_IPV4_LEN_MAX                     16

/*   Length of common name string */
#define NETDEV_NAME_MAX_LEN                    (20u)

/* CODE   Length of common code */
#define NETDEV_CODE_STR_MAX_LEN                (48u)

/*  Maximum length of date string "2008-10-02 09:25:33.001 GMT" */
#define NETDEV_MAX_DATE_STRING_LEN             (64u)

/*  Length of time string "hh:mm:ss" */
#define NETDEV_SIMPLE_TIME_LEN                 (12u)

/*  Length of date string "YYYY-MM-DD"*/
#define NETDEV_SIMPLE_DATE_LEN                 (12u)

/*   Maximum number of alarm inputs */
#define NETDEV_MAX_ALARM_IN_NUM                 64

/*   Maximum number of alarm outputs */
#define NETDEV_MAX_ALARM_OUT_NUM                64

/*   Number of scheduled time sections in a day */
#define NETDEV_PLAN_SECTION_NUM                 8

/*  Total number of plans allowed in a week, including Monday to Sunday, and holidays */
#define NETDEV_PLAN_NUM_AWEEK                   8

/*   Maximum number of motion detection areas allowed */
#define NETDEV_MAX_MOTION_DETECT_AREA_NUM       4

/*   Maximum number of privacy mask areas allowed */
#define NETDEV_MAX_PRIVACY_MASK_AREA_NUM        8

/*   Maximum number of tamper-proof areas allowed */
#define NETDEV_MAX_TAMPER_PROOF_AREA_NUM        1

/*   Maximum number of text overlays allowed for a channel */
#define NETDEV_MAX_TEXTOVERLAY_NUM              6

/*   Maximum number of video streams */
#define NETDEV_MAX_VIDEO_STREAM_NUM             8

/*  Month of the year */
#define NETDEV_MONTH_OF_YEAR                    12

/*  Day of the month */
#define NETDEV_DAYS_OF_MONTH                    32

/*   Length of device ID */
#define NETDEV_DEV_ID_LEN                       64

/*   Length of device serial number */
#define NETDEV_SERIAL_NUMBER_LEN                32

/*   Maximum number of queries allowed at a time */
#define NETDEV_MAX_QUERY_NUM                    200

/*   Total number of queries allowed */
#define NETDEV_MAX_QUERY_TOTAL_NUM              2000

/*  Maximum number of IPC cameras */
#define NETDEV_MAX_IPC_NUM                      128

/*   Maximum number of presets */
#define NETDEV_MAX_PRESET_NUM                   255

/*   Maximum number of presets for preset patrol */
#define NETDEV_MAX_CRUISEPOINT_NUM              32

/*   Maximum number of routes for preset patrol */
#define NETDEV_MAX_CRUISEROUTE_NUM              16

/*   PTZ rotating speed */
#define NETDEV_MIN_PTZ_SPEED_LEVEL              1
#define NETDEV_MAX_PTZ_SPEED_LEVEL              9

/*  Maximum / Minimum values for image parameters (brightness, contrast, hue, saturation) */
#define NETDEV_MAX_VIDEO_EFFECT_VALUE           255
#define NETDEV_MIN_VIDEO_EFFECT_VALUE           0

/*  Minimum values for image parameters (Gama) */
#define NETDEV_MAX_VIDEO_EFFECT_GAMMA_VALUE     10

/*   Maximum connection timeout */
#define NETDEV_MAX_CONNECT_TIME_VALUE           75000

/*   Minimum connection timeout */
#define NETDEV_MIN_CONNECT_TIME_VALUE           300

/*   Maximum number of users */
#define NETDEV_MAX_USER_NUM                     (256 + 32)

/*   Maximum number of channels allowed for live preview */
#define NETDEV_MAX_REALPLAY_NUM                 128

/*   Maximum number of channels allowed for playback or download */
#define NETDEV_MAX_PALYBACK_NUM                 128

/*   Maximum number of alarm channels */
#define NETDEV_MAX_ALARMCHAN_NUM                128

/*   Maximum number of channels allowed for formatting hard disk */
#define NETDEV_MAX_FORMAT_NUM                   128

/*   Maximum number of channels allowed for file search */
#define NETDEV_MAX_FILE_SEARCH_NUM              2000

/*   Maximum number of channels allowed for log search */
#define NETDEV_MAX_LOG_SEARCH_NUM               2000

/*   Maximum number of channels allowed for creating transparent channels */
#define NETDEV_MAX_SERIAL_NUM                   2000

/*   Maximum number of channels allowed for upgrade */
#define NETDEV_MAX_UPGRADE_NUM                  256

/*   Maximum number of channels allowed for audio forwarding */
#define NETDEV_MAX_VOICE_COM_NUM                256

/*   Maximum number of channels allowed for audio broadcast */
#define NETDEV_MAX_VOICE_BROADCAST_NUM          256

/*  Maximum timeout, unit: ms */
#define NETDEV_MAX_CONNECT_TIME                 75000

/*  Minimum timeout, unit: ms */
#define NETDEV_MIN_CONNECT_TIME                 300

/*  Default timeout, unit: ms */
#define NETDEV_DEFAULT_CONNECT_TIME             3000

/*  Number of connection attempts */
#define NETDEV_CONNECT_TRY_TIMES                1

/*  User keep-alive interval */
#define NETDEV_KEEPLIVE_TRY_TIMES               3

/*  Number of OSD text overlays */
#define NETDEV_OSD_TEXTOVERLAY_NUM              6

/*  Length of OSD texts */
#define NETDEV_OSD_TEXT_MAX_LEN                 (64 + 4)

/*  Maximum number of OSD type */
#define NETDEV_OSD_TYPE_MAX_NUM                 26

/*  Maximum number of OSD time format type */
#define NETDEV_OSD_TIME_FORMAT_MAX_NUM          7

/*  Maximum number of OSD date format type */
#define NETDEV_OSD_DATE_FORMAT_MAX_NUM          15

/*  Maximum number of alarms a user can get */
#define NETDEV_PULL_ALARM_MAX_NUM               8

/*   Maximum number of patrol routes allowed  */
#define NETDEV_TRACK_CRUISE_MAXNUM               1

/*   Minimum volume */
#define NETDEV_AUDIO_SOUND_MIN_VALUE            0

/*   Maximum volume */
#define NETDEV_AUDIO_SOUND_MAX_VALUE            255

/*   Minimum volume */
#define NETDEV_MIC_SOUND_MIN_VALUE              0

/*   Maximum volume */
#define NETDEV_MIC_SOUND_MAX_VALUE              255

/*   Screen Info Row */
#define NETDEV_SCREEN_INFO_ROW                  18

/*   Screen Info Column */
#define NETDEV_SCREEN_INFO_COLUMN               22

/* Length of IP */
#define NETDEV_IP_LEN                           64

/*  Maximum length of buffer */
#define NETDEV_BUFFER_MAX_LEN                   1024

/*  Maximum number of channel */
#define NETDEV_CHANNEL_MAX                      512

/*  Maximum number of resolution */
#define NETDEV_RESOLUTION_NUM_MAX               32

/*  Maximum number of days in a month */
#define NETDEV_MONTH_DAY_MAX                    31

/*  Maximum number of encode type */
#define NETDEV_VIDEO_ENCODE_TYPE_MAX            16

/*  Maximum number of people count */
#define   NETDEV_PEOPLE_CNT_MAX_NUM             31

/* Length of wifi sniffer MAC */
#define NETDEV_WIFISNIFFER_MAC_MAX_NUM          64

/* wifi sniffer MAC Maximum number of wifi sniffer MAC array */
#define NETDEV_WIFISNIFFER_MAC_ARRY_MAX_NUM     128

/*  Maximum number of Disk */
#define NETDEV_DISK_MAX_NUM                     256

/*  Maximum number of image quality level */
#define NETDEV_IMAGE_QUALITY_MAX_NUM            9

/*  Maximum number of bit rate mode */
#define NETDEV_BIT_RATE_TYPE_MAX_NUM            2

/*  Maximum number of video compression */
#define NETDEV_ENCODE_FORMAT_MAX_NUM            3

/*  Maximum number of smart image encoding mode */
#define NETDEV_SMART_ENCODE_MODEL_MAX_NUM       3

/* Maximum number of GOP type */
#define NETDEV_GOP_TYPE_MAX_NUM                 4


/* BEGIN****************************  Error codes ************************************************************/
#define NETDEV_E_SUCCEED                        0           /*   Succeeded */
#define NETDEV_E_FAILED                         -1          /*   Failed */

#define NETDEV_E_COMMON_FAILED                  1           /*   Common error */
#define NETDEV_E_DEV_COMMON_FAILED              2           /*   Common error returned by device */
#define NETDEV_E_SYSCALL_FALIED                 3           /*   Failed to call system function. See errno */
#define NETDEV_E_NULL_POINT                     4           /*   Null pointer */
#define NETDEV_E_INVALID_PARAM                  5           /*   Invalid parameter */
#define NETDEV_E_INVALID_MODULEID               6           /*   Invalid module ID */
#define NETDEV_E_NO_MEMORY                      7           /*   Failed to allocate memory */
#define NETDEV_E_NOT_SUPPORT                    8           /*   Not supported by device */
#define NETDEV_E_SDK_SOCKET_LSN_FAIL            9           /*  listen  Failed to create socket listen */
#define NETDEV_E_INIT_MUTEX_FAIL                10          /*   Failed to initialize lock */
#define NETDEV_E_INIT_SEMA_FAIL                 11          /*   Failed to initialize semaphore */
#define NETDEV_E_ALLOC_RESOURCE_ERROR           12          /*   Error occurred during SDK resource allocation */
#define NETDEV_E_SDK_NOINTE_ERROR               13          /*   SDK not initialized */
#define NETDEV_E_ALREDY_INIT_ERROR              14          /*   SDK already initialized */
#define NETDEV_E_HAVEDATA                       15          /*    Data not all sent */
#define NETDEV_E_NEEDMOREDATA                   16          /*   More data required  */
#define NETDEV_E_CONNECT_ERROR                  17          /*   Failed to create connection */
#define NETDEV_E_SEND_MSG_ERROR                 18          /*   Failed to send request message */
#define NETDEV_E_TIMEOUT                        19          /*   Message timeout */
#define NETDEV_E_DECODE_RSP_ERROR               20          /*   Failed to decode response message */
#define NETDEV_E_SOCKET_RECV_ERROR              21          /*   Socket failed to receive message */
#define NETDEV_E_NUM_MAX_ERROR                  22          /*   Maximum number reached. The assigned numbers of registration connections and preview connections reached the maximum supported by SDK */
#define NETDEV_E_GET_PORT_ERROR                 24          /*   Failed to obtain local port number */
#define NETDEV_E_CREATE_THREAD_FAIL             25          /*   Failed to create thread */
#define NETDEV_E_NOENOUGH_BUF                   26          /*   Buffer is too small for receiving device data */
#define NETDEV_E_GETLOCALIPANDMACFAIL           27          /*   Failed to obtain the IP or MAC address of the local PC */
#define NETDEV_E_RESCODE_NO_EXIST               28          /*   Resource code not exist */
#define NETDEV_E_MSG_DATA_INVALID               31          /*   Incorrect message content */
#define NETDEV_E_GET_CAPABILITY_ERROR           32          /*   Failed to obtain capabilities */
#define NETDEV_E_USER_NOT_BIND                  33          /*    User not subscribed to alarms */
#define NETDEV_E_AUTHORIZATIONFAIL              34          /*   User authentication failed */
#define NETDEV_E_BINDNOTIFY_FAIL                35          /*   Failed to bind alarms*/
#define NETDEV_E_NOTADMIN                       36          /*   Not enough permission. In Windows, it is normally because the operator is not an administrator. */
#define NETDEV_E_DEVICE_FACTURER_ERR            37          /*  Manufacturers that are not supported */
#define NETDEV_E_NONSUPPORT                     38          /*   Function not supported */
#define NETDEV_E_TRANSFILE_FAIL                 39          /*   File transmission failed */
#define NETDEV_E_JSON_ERROR                     40          /*    Json common error */
#define NETDEV_E_NO_RESULT                      41          /*  No result */
#define NETDEV_E_DEVICE_TYPE_ERR                42          /*  Device type that are not supported */

/*   User-related error codes */
#define NETDEV_E_USER_WRONG_PASSWD              101         /*   Incorrect password */
#define NETDEV_E_USER_LOGIN_MAX_NUM             102         /*   Number of login users reached the upper limit */
#define NETDEV_E_USER_NOT_ONLINE                103         /*   User not online */
#define NETDEV_E_USER_NO_SUCH_USER              104         /*   User not online */
#define NETDEV_E_USER_NO_AUTH                   105         /*   User has no rights */
#define NETDEV_E_USER_MAX_NUM                   106         /*   Reached the upper limitno more users can be added */
#define NETDEV_E_USER_EXIST                     107         /*   User already exists */
#define NETDEV_E_USER_PASSWORD_CHANGE           108         /*   Password changed */
#define NETDEV_E_REMOTE_USER_WITH_WEAK_PASSWD   109         /*   Remote user with weak password */

/*   Service-related error codes */

/*   Playback-related error codes */
#define NETDEV_E_VOD_PLAY_END                   250         /*   Playback ended */
#define NETDEV_E_VOD_NO_CM                      251         /*   Playback controlling module not exist */
#define NETDEV_E_VOD_OVER_ABILITY               252         /*   Beyond playback capability */
#define NETDEV_E_VOD_NO_RECORDING_CM            253         /*   Recording file controlling module not exist */
#define NETDEV_E_VOD_NO_RECORDING               254         /*    No recording */
#define NETDEV_E_VOD_NO_REPLAYURL               255         /*    Cannot get the URL for playback*/


/*   PTZ-related error codes */
#define NETDEV_E_PTZ_SET_PRESET_FAILED              300         /*   Failed to set preset */
#define NETDEV_E_PTZ_QUERY_PRESET_FAILED            301         /*   Failed to query preset */
#define NETDEV_E_PTZ_QUERY_TRACK_FAILED             302         /*   Failed to query route */
#define NETDEV_E_PTZ_START_RECORD_TRACK_FAILED      303         /*   Failed to start route recording */
#define NETDEV_E_PTZ_STOP_RECORD_TRACK_FAILED       304         /*   Failed to end route recording */
#define NETDEV_E_PTZ_QUERY_CRUISE_FAILED            305         /*   Failed to query patrol route */
#define NETDEV_E_PTZ_SET_CRUISE_FAILED              306         /*   Failed to set patrol route */
#define NETDEV_E_PTZ_CTRL_FAILED                    307         /*   PTZ operation failed */
#define NETDEV_E_PTZ_PRESET_IN_CRUISE               308         /*   Preset is being used in patrol route and cannot be deleted */
#define NETDEV_E_PTZ_CRUISEPOINT_ERR                309         /*   Discontinuous presets */
#define NETDEV_E_PTZ_TRACK_ISUSED                   310         /*   Route is in use and cannot be deleted */
#define NETDEV_E_PTZ_SERIALMODE_MISMATCH            311         /*   Serial modes do not match */
#define NETDEV_E_PTZ_TRACK_NOT_EXIST                312         /*   Route does not exist */
#define NETDEV_E_PTZ_MODE_CRUISE_FULL               313         /*   Route points are full */


/* SOAP  SOAP-related error codes */
#define NETDEV_E_DEVICE_STREAM_FULL                 500         /*   Device stream full */
#define NETDEV_E_DEVICE_STREAM_CLOSED               501         /*   Device stream closed */
#define NETDEV_E_DEVICE_STREAM_NONEXIST             502         /*   Device stream does not exist */

#define NETDEV_E_COMMON_FAIL_STAT                   503         /*   Failed to read file (directory) status */
#define NETDEV_E_COMMON_FILE_NONEXIST               504         /*   File does not exist */
#define NETDEV_E_COMMON_MKDIR_ERR                   505         /*   Failed to create directory */
#define NETDEV_E_SUBSCRIBE_FULL                     506         /*   Subscription is full for current user */
#define NETDEV_E_UPGRADE_NOTADMIN                   507         /*   Only admin can upgrade */
#define NETDEV_E_UPGRADE_INVALID                    508         /*    Upgrade not started */
#define NETDEV_E_UPGRADE_INPROCESS                  509         /*    Upgrade in process */
#define NETDEV_E_UPGRADE_NOMEMORY                   510         /*    Insufficient memory for upgrade */
#define NETDEV_E_UPGRADE_FILE_OPEN_ERR              511         /*    Error occurred while opening the mirror file during upgrade */
#define NETDEV_E_UPGRADE_DEVICE_ERR                 512         /*    Error occurred while upgrading FLASH */
#define NETDEV_E_UPGRADE_BUSY                       513         /*   Cannot load multiple upgrade processes at the same time */
#define NETDEV_E_UPGRADE_FAIL_TIMEOUT               514         /*   Upgrade timeout */
#define NETDEV_E_INVALID_CONFIGFILE                 515         /*   Invalid configuration file */
#define NETDEV_E_STOR_RESOURCE_NOTINIT              516         /*   Storage resource not allocated */

#define NETDEV_E_PLAYER_BASE_ERR                    1000        /*   Basic decoding error code */
#define NETDEV_E_PLAYER_FAIL                        1001        /*   Basic decoding error code */
#define NETDEV_E_PLAYER_INVALID_PARAM               1002        /*   Invalid input parameter */
#define NETDEV_E_PLAYER_NO_MEMORY                   1003        /*   Not enough system memory */
#define NETDEV_E_PLAYER_SOCKET_FAIL                 1004        /*   Failed to create SOCKET */
#define NETDEV_E_PLAYER_RECV_FAIL                   1005        /*   Failed to receive */
#define NETDEV_E_PLAYER_RECV_ZERO                   1006        /*   None received */
#define NETDEV_E_PLAYER_NOT_SUPPORT                 1007        /*   Currently not supported */
#define NETDEV_E_PLAYER_CREATETHREAD_FAILED         1008        /*   Failed to create the thread */
#define NETDEV_E_PLAYER_OPENDL_FAILED               1009        /*   Failed to load the dynamic library */
#define NETDEV_E_PLAYER_SYMDL_FAILED                1010        /*   Failed to get the dynamic library */
#define NETDEV_E_PLAYER_SEND_FAILED                 1011        /*   Failed to send */
#define NETDEV_E_PLAYER_EACCES                      1012        /*   No permission to create the file */
#define NETDEV_E_PLAYER_FILE_NOT_FIND               1013        /*   Failed to find the file to read */
#define NETDEV_E_PLAYER_LOG_CLOSE                   1014        /*   Close log */

/*********************** Player ********************************/
#define NETDEV_E_FAIL_TO_INIT_EZPLAYER              1257        /*   Failed to initialize the player */
#define NETDEV_E_FAIL_TO_ALLOC_PORT_RES             1258        /*   Failed to allocate playing channel resources */
#define NETDEV_E_FAIL_TO_GET_PORT_RES               1259        /*   Failed to get playing channel resources */
#define NETDEV_E_BUFFER_QUEUE_FULL                  1260        /*   Cache queue full */
#define NETDEV_E_BUFFER_QUEUE_EMPTY                 1261        /*   Cache queue empty */
#define NETDEV_E_OPEN_FILE_FAILED                   1262        /*   Failed to open the file */
#define NETDEV_E_FILE_READ_END                      1263        /*   The file is read */
#define NETDEV_E_FILE_DISKSPACE_FULL                1264        /*   Disk space full */
#define NETDEV_E_FILE_READ_FAIL                     1265        /*   Failed to read */
#define NETDEV_E_MCM_MIC_NOT_EXIST                  1266        /*   The microphone does not exist */
#define NETDEV_E_TS_PACKET_IN_THE_ROUGH             1267        /*   TS packing not finished */
#define NETDEV_E_FILE_RECORD_FINISH                 1268        /*   Recording saved */
#define NETDEV_E_VIDEO_RESOLUTION_CHANGE            1269        /*   Resolution changed */
#define NETDEV_E_VIDEO_RECORD_PART                  1270        /*  */

#define NETDEV_E_FAIL_TO_OPEN_STREAM                1513        /*   Failed to start media streaming */
#define NETDEV_E_FAIL_TO_CLOSE_STREAM               1514        /*   Failed to close media streaming */
#define NETDEV_E_FAIL_TO_RECV_DATA                  1515        /*   Failed to receive data due to network error */
#define NETDEV_E_FAIL_TO_PROCESS_MEDIA_DATA         1516        /*   Failed to handle media data */
#define NETDEV_E_NOT_START_PLAY                     1517        /*   Playing not started in playing channel */
#define NETDEV_E_FAIL_TO_INPUT_DATA                 1518        /*   Failed to enter media stream data */
#define NETDEV_E_INPUTDATA_BUFFER_FULL              1519        /*   Input data cache full */
#define NETDEV_E_FAIL_TO_SET_PROCESS_DATA_CB        1520        /*   Failed to set media stream data callback function */
#define NETDEV_E_VOICE_RUNNING                      1521        /*   Error occurred when running voice service */
#define NETDEV_E_FAIL_TO_OPEN_VOICE_SVC             1522        /*   Failed to start voice service */
#define NETDEV_E_FAIL_TO_CLOSE_VOICE_SVC            1523        /*   Failed to close voice service */
#define NETDEV_E_UNKNOWN_STREAM_TYPE                1524        /*   Unknown media stream */
#define NETDEV_E_PACKET_LOSE                        1525        /*   Packet loss */
#define NETDEV_E_NEED_MORE_PACKET                   1526        /*   More packets are needed for the packing */
#define NETDEV_E_FAIL_TO_CREATE_DECODE              1527        /*   Failed to create the decoder */
#define NETDEV_E_FAIL_TO_DECODE                     1528        /*  Failed to decode */
#define NETDEV_E_RECV_DATA_NOTENOUGH                1529        /*   Not enough data received */
#define NETDEV_E_RENDER_RES_FULL                    1530        /*   Display resources full */
#define NETDEV_E_RENDER_RES_NOT_EXIST               1531        /*   Display resources do not exist */
#define NETDEV_E_CREATE_DEV_FAILED                  1532        /*   Failed to create the resources */
#define NETDEV_E_AUDIO_RES_NOT_EXIST                1533        /*   Audio resources do not exist */
#define NETDEV_E_IHW265D_NEED_MORE_BITS             1534        /*   Decoder requires more data */
#define NETDEV_E_FAIL_TO_CREATE_ENCODE              1535        /*   Failed to create encoder */
#define NETDEV_E_CAPTURE_RES_EXIST                  1536        /*   Capture resources do not exist */
#define NETDEV_E_RECORD_STARTED                     1537        /*   Recording already opened */
#define NETDEV_E_NEED_WAIT_DECODEC                  1538        /*   Decoding in progress, please wait */
#define NETDEV_E_MORE_DATA_NEED_PACKET              1539        /*   Too much data, still need packing */

/*   Live video error codes */
#define NETDEV_E_LIVE_EXISTED                       2000        /*   Live video service already established */
#define NETDEV_E_LIVE_INPUT_NOT_READY               2001        /*   Media stream not ready */
#define NETDEV_E_LIVE_OUTPUT_BUSY                   2002        /*   Display resource is busy for live video service */
#define NETDEV_E_LIVE_CB_NOTEXIST                   2003        /*   Control module for live video not exist */
#define NETDEV_E_LIVE_STREAM_FULL                   2004        /*   Live stream resource full */

/*   Capture-related error codes */
#define NETDEV_E_CAPTURE_NO_SUPPORT_FORMAT          2100        /*   Format of captured image not supported */
#define NETDEV_E_CAPTURE_NO_ENOUGH_CAPACITY         2101        /*   Insufficient disk space */
#define NETDEV_E_CAPTURE_NO_DECODED_PICTURE         2102        /*   No decoded image for capture */
#define NETDEV_E_CAPTURE_SINGLE_FAILED              2103        /*   Single capture failed */

/*   Error codes related to two-way audio */
#define NETDEV_E_AUDIO_EXISTED                      2200        /*   Two-way audio already exists */
#define NETDEV_E_AUDIO_NO_EXISTED                   2201        /*   Two-way audio service does not exist */
#define NETDEV_E_AUDIO_RESCODE_INVALID              2202        /*   Invalid two-way audio resource code */
#define NETDEV_E_AUDIO_RES_USED_BY_TALK             2203        /*   Audio resource is being used by two-way audio */
#define NETDEV_E_AUDIO_FAILED                       2204        /*   Two-way audio failed */
#define NETDEV_E_AUDIO_AUDIOBCAST_FULL              2205        /*   No more audio service allowed */

/* END*********************   Error codes *********************************************************** */

/* BEGIN:******************   Enumeration value ***************************************************** */

/**
 * @enum tagNETDEVChannelStatus
 * @brief   Channel status Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVChannelStatus
{
    NETDEV_CHL_STATUS_OFFLINE = 0,            /*   Channel offline */
    NETDEV_CHL_STATUS_ONLINE = 1,             /*   Channel online */
    NETDEV_CHL_STATUS_UNBIND = 2,             /*   Channel unbind */
    NETDEV_CHL_STATUS_INVALID
}NETDEV_CHANNEL_STATUS_E;

/**
 * @enum tagNETDEVCameraType
 * @brief   Camera type Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVCameraType
{
    NETDEV_CAMERA_TYPE_FIX         = 0,            /*   Fixed camera */
    NETDEV_CAMERA_TYPE_PTZ         = 1,            /*   PTZ camera */

    NETDEV_CAMERA_TYPE_INVALID     = 0xFF          /*   Invalid value */
}NETDEV_CAMERA_TYPE_E;

/**
 * @enum tagNETDEVLiveStreamIndex
 * @brief    Live stream index Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVLiveStreamIndex
{
    NETDEV_LIVE_STREAM_INDEX_MAIN  = 0,   /*   Main stream */
    NETDEV_LIVE_STREAM_INDEX_AUX   = 1,   /*   Sub stream */
    NETDEV_LIVE_STREAM_INDEX_THIRD = 2,   /*   Third stream */

    NETDEV_LIVE_STREAM_INDEX_INVALID
}NETDEV_LIVE_STREAM_INDEX_E;

/**
 * @enum tagHOSTType
 * @brief IP   Protocol type Enumeration definition
 * @attention  None
 */
typedef enum tagHOSTType
{
    NETDEV_NETWORK_HOSTTYPE_IPV4 = 0,               /* IPv4 */
    NETDEV_NETWORK_HOSTTYPE_IPV6 = 1,               /* IPv6 */
    NETDEV_NETWORK_HOSTTYPE_DNS  = 2                /* DNS */
}NETDEV_HOSTTYPE_E;


/**
 * @enum tagNETDEVProtocal
 * @brief    Media transport protocol Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVProtocal
{
    NETDEV_TRANSPROTOCAL_RTPUDP = 0,         /* UDP */
    NETDEV_TRANSPROTOCAL_RTPTCP = 1          /* TCP */
}NETDEV_PROTOCAL_E;

/**
 * @enum tagNETDEVMediaFileFormat
 * @brief    Media file format Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVMediaFileFormat
{
    NETDEV_MEDIA_FILE_MP4                   = 0,    /*  mp4 media file (Audio + Video) */
    NETDEV_MEDIA_FILE_TS                    = 1,    /*  TS media file (Audio + Video) */
    NETDEV_MEDIA_FILE_MP4_ADD_TIME          = 2,    /*  MP4 media file with time in file name (Audio + Video) */
    NETDEV_MEDIA_FILE_TS_ADD_TIME           = 3,    /*  TS media file with time in file name (Audio + Video) */
    NETDEV_MEDIA_FILE_AUDIO_TS              = 4,    /*  TS audio file (Only audio) */
    NETDEV_MEDIA_FILE_AUDIO_MP4             = 5,    /*  MP4 audio file (Only audio) */
    NETDEV_MEDIA_FILE_AUDIO_TS_ADD_TIME     = 6,    /*  TS audio file with time in file name (Only audio) */
    NETDEV_MEDIA_FILE_AUDIO_MP4_ADD_TIME    = 7,    /*  MP4 audio file with time in file name (Only audio) */
    NETDEV_MEDIA_FILE_INVALID
}NETDEV_MEDIA_FILE_FORMAT_E;

/**
 * @enum tagNETDEVPlayerVideoCodeType
 * @brief    Player Video encoding format Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVPlayerVideoCodeType
{
    NETDEV_PLAYER_VIDEO_CODE_MPEG2     = 0,          /* MPEG-2 */
    NETDEV_PLAYER_VIDEO_CODE_MPEG4     = 1,          /* MPEG-4 */
    NETDEV_PLAYER_VIDEO_CODE_H264      = 2,          /* H.264 */
    NETDEV_PLAYER_VIDEO_CODE_MJPEG     = 3,          /* MJPEG */
    NETDEV_PLAYER_VIDEO_CODE_H265      = 4,          /* H.265 */

    NETDEV_PLAYER_VIDEO_CODE_INVALID
}NETDEV_PLAYER_VIDEO_CODE_TYPE_E;

/**
 * @enum tagNETDEVVideoCodeType
 * @brief    Video encoding format Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVVideoCodeType
{
    NETDEV_VIDEO_CODE_MJPEG = 0,          /* MJPEG */
    NETDEV_VIDEO_CODE_H264  = 1,          /* H.264 */
    NETDEV_VIDEO_CODE_H265  = 2,          /* H.265 */
    NETDEV_VIDEO_CODE_INVALID
}NETDEV_VIDEO_CODE_TYPE_E;

/**
 * @enum tagNETDEVVideoFrameType
 * @brief    Video frame type Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVVideoFrameType
{
    NETDEV_VIDEO_FRAME_I = 0,               /* I-frame */
    NETDEV_VIDEO_FRAME_P = 1,               /* P-frame */
    NETDEV_VIDEO_FRAME_B = 2                /* B-frame */
}NETDEV_VIDEO_FRAME_TYPE_E;

/**
* @enum tagNetDEVAudioEncodeType
* @brief  Audio encode type
* @attention  None
*/
typedef enum tagNetDEVAudioEncodeType
{
    NETDEV_AUDIO_ENCODE_G711U = 0,          /* Audio up to G.711U-law standard*/
    NETDEV_AUDIO_ENCODE_MP2   = 1,          /* Audio up to MP2 standard */
    NETDEV_AUDIO_ENCODE_AAC   = 2,          /* Audio up to AAC standard*/
    NETDEV_AUDIO_ENCODE_G711A = 3,          /* Audio up to G.711A-law standard*/
    NETDEV_AUDIO_ENCODE_PCM   = 4,          /* Audio up to PCM law standard*/
    NETDEV_AUDIO_ENCODE_NULL  = 5           /*  No audio */
}NETDEV_AUDIO_ENCODE_TYPE_E;

/**
* @enum tagNetDEVWaveFormatInfo
* @brief  Wave format info
* @attention   None
*/
typedef enum tagNetDEVWaveFormatInfo
{
    NETDEV_WAVE_FORMAT_PCM8M16        = 0,        /* PCM,8K,,16 PCM,8k sampling rate,16 bit sampling*/
    NETDEV_WAVE_FORMAT_PCM16M16       = 1,        /* PCM,16K,,16 PCM,16k sampling rate,16 bit sampling*/
    NETDEV_WAVE_FORMAT_PCM441M16      = 2,        /* PCM,44.1K,,16 PCM,44.1k sampling rate,16 bit sampling*/
    NETDEV_WAVE_FORMAT_PCM11025M16    = 3,        /* PCM,11.025K,,16 PCM,11.025k sampling rate,16 bit sampling*/
    NETDEV_WAVE_FORMAT_UNKNOWN
}NETDEV_WAVE_FORMAT_INFO_E;

/**
 * @enum tagNETDEVRenderScale
 * @brief    Video display ratio Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVRenderScale
{
    NETDEV_RENDER_SCALE_FULL        = 0,                  /*   Stretch */
    NETDEV_RENDER_SCALE_PROPORTION  = 1,                  /*   Scale */

    NETDEV_RENDER_SCALE_INVALID     = 0xFF
}NETDEV_RENDER_SCALE_E;

/**
 * @enum tagNETDEVPictureFormat
 * @brief   Picture type Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVPictureFormat
{
    NETDEV_PICTURE_BMP = 0,                  /* bmp  Picture format is bmp */
    NETDEV_PICTURE_JPG = 1,                  /* jpg  Picture format is jpg */

    NETDEV_PICTURE_INVALID
}NETDEV_PICTURE_FORMAT_E;

/**
 * @enum tagNETDEVVideoQuality
 * @brief    Video image quality Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVVideoQuality
{
    NETDEV_VQ_L0 = 0,                    /*   Highest */
    NETDEV_VQ_L1 = 1,
    NETDEV_VQ_L2 = 4,                    /*   Higher */
    NETDEV_VQ_L3 = 8,
    NETDEV_VQ_L4 = 12,                   /*   Medium */
    NETDEV_VQ_L5 = 16,
    NETDEV_VQ_L6 = 20,                   /*   Low */
    NETDEV_VQ_L7 = 24,
    NETDEV_VQ_L8 = 28,                   /*   Lower */
    NETDEV_VQ_L9 = 31,                   /*   Lowest */

    NETDEV_VQ_LEVEL_INVALID = -1         /*   Valid */
}NETDEV_VIDEO_QUALITY_E;

/**
 * @enum tagNETDEVPictureSize
 * @brief   Image resolution Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVPictureSize
{
    NETDEV_PICTURE_SIZE_D1     = 0,           /* D1 */
    NETDEV_PICTURE_SIZE_4CIF   = 1,           /* 4CIF */
    NETDEV_PICTURE_SIZE_2CIF   = 2,           /* 2CIF */
    NETDEV_PICTURE_SIZE_CIF    = 3,           /* CIF */
    NETDEV_PICTURE_SIZE_960H   = 4,           /* 960H */
    NETDEV_PICTURE_SIZE_QCIF   = 5,           /* QCIF */
    NETDEV_PICTURE_SIZE_HALFD1 = 6,           /* HALFD1 */
    NETDEV_PICTURE_SIZE_720    = 7,           /* 720 */
    NETDEV_PICTURE_SIZE_1080   = 8,           /* 1080 */
    NETDEV_PICTURE_SIZE_XGA    = 9,           /* 1024*768 */
    NETDEV_PICTURE_SIZE_SXGA   = 10,          /* 1280*1024 */

    NETDEV_PICTURE_SIZE_INVALID               /*   Invalid value */
}NETDEV_PICTURE_SIZE_E;

/**
 * @enum tagNETDEVPtzCmdEnum
 * @brief   PTZ commands Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVPtzCmdEnum
{
#if 0
    NETDEV_PTZ_IRISCLOSE_STOP       =0x0101,       /*   Iris close stop */
    NETDEV_PTZ_IRISCLOSE            =0x0102,       /*   Iris close */
    NETDEV_PTZ_IRISCLOSE_STOP        0x0103,       /*   Iris open stop */
    NETDEV_PTZ_IRISOPEN             =0x0104,       /*   Iris open */
#endif
    NETDEV_PTZ_FOCUSNEAR_STOP       =0x0201,       /*   Focus near stop */
    NETDEV_PTZ_FOCUSNEAR            =0x0202,       /*   Focus near */
    NETDEV_PTZ_FOCUSFAR_STOP        =0x0203,       /*   Focus far stop */
    NETDEV_PTZ_FOCUSFAR             =0x0204,       /*   Focus far */

    NETDEV_PTZ_ZOOMTELE_STOP        = 0x0301,       /*   Zoom in stop */
    NETDEV_PTZ_ZOOMTELE             = 0x0302,       /*   Zoom in */
    NETDEV_PTZ_ZOOMWIDE_STOP        = 0x0303,       /*   Zoom out stop */
    NETDEV_PTZ_ZOOMWIDE             = 0x0304,       /*   Zoom out */
    NETDEV_PTZ_TILTUP               = 0x0402,       /*   Tilt up */
    NETDEV_PTZ_TILTDOWN             = 0x0404,       /*   Tilt down */
    NETDEV_PTZ_PANRIGHT             = 0x0502,       /*   Pan right */
    NETDEV_PTZ_PANLEFT              = 0x0504,       /*   Pan left */
    NETDEV_PTZ_LEFTUP               = 0x0702,       /*   Move up left */
    NETDEV_PTZ_LEFTDOWN             = 0x0704,       /*   Move down left */
    NETDEV_PTZ_RIGHTUP              = 0x0802,       /*   Move up right */
    NETDEV_PTZ_RIGHTDOWN            = 0x0804,       /*   Move down right */

#if 0
    NETDEV_PTZ_PRESAVE              = 0x0601,       /*   Save preset */
    NETDEV_PTZ_PRECALL              = 0x0602,       /*   Call preset */
    NETDEV_PTZ_PREDEL               = 0x0603,       /*   Delete preset */
#endif

    NETDEV_PTZ_ALLSTOP              = 0x0901,       /*   All-stop command word */
    NETDEV_PTZ_FOCUS_AND_IRIS_STOP  = 0x0907,       /* .  Focus & Iris-stop command word */

    NETDEV_PTZ_TRACKCRUISE          = 0x1001,       /*   Start route patrol*/
    NETDEV_PTZ_TRACKCRUISESTOP      = 0x1002,       /*   Stop route patrol*/
    NETDEV_PTZ_TRACKCRUISEREC       = 0x1003,       /*   Start recording route */
    NETDEV_PTZ_TRACKCRUISERECSTOP   = 0x1004,       /*   Stop recording route */
    NETDEV_PTZ_TRACKCRUISEADD       = 0x1005,       /*   Add patrol route */
    NETDEV_PTZ_TRACKCRUISEDEL       = 0x1006,       /*   Delete patrol route */

    NETDEV_PTZ_AREAZOOMIN           = 0x1101,       /*   Zoom in area */
    NETDEV_PTZ_AREAZOOMOUT          = 0x1102,       /*   Zoom out area */
    NETDEV_PTZ_AREAZOOM3D           = 0x1103,       /*   3D positioning */

    NETDEV_PTZ_BRUSHON              = 0x0A01,       /*   Wiper on */
    NETDEV_PTZ_BRUSHOFF             = 0x0A02,       /*   Wiper off */

    NETDEV_PTZ_LIGHTON              = 0x0B01,       /*   Lamp on */
    NETDEV_PTZ_LIGHTOFF             = 0x0B02,       /*   Lamp off */

    NETDEV_PTZ_HEATON               = 0x0C01,       /*   Heater on */
    NETDEV_PTZ_HEATOFF              = 0x0C02,       /*   Heater off */

    NETDEV_PTZ_SNOWREMOINGON        = 0x0E01,       /*   Snowremoval on */
    NETDEV_PTZ_SNOWREMOINGOFF       = 0x0E02,       /*   Snowremoval off  */

#if 0
    NETDEV_PTZ_ABSPOSITION          = 0x0902,       /*   Set absolute position of camera */
    NETDEV_PTZ_GUARD                = 0x0903,       /*   Return to home position (this command is not implemented on the PTZ template) */
    NETDEV_PTZ_SPEEDSET             = 0x0904,       /*  Set speed */

    NETDEV_PTZ_INFRAREDON           = 0x0D01,       /*   IR on */
    NETDEV_PTZ_INFRAREDOFF          = 0x0D02,       /*   IR off */

    NETDEV_PTZ_PRESETCRUISE         = 0x1001,       /*   Preset-based PTZ patrol (the command word is not implemented on the PTZ template) */
    NETDEV_PTZ_PRESETCRUISESTOP     = 0x1002,       /*   Preset-based PTZ patrol stop (the command word is not implemented on the PTZ template) */
    NETDEV_PTZ_CRUISEDEL            = 0X1003,       /*   Delete route */
    NETDEV_PTZ_CRUISEADDPRESET      = 0x1004,       /*   Add preset to route */
    NETDEV_PTZ_CRUISEADDSTART       = 0x1005,       /*   Start adding preset to route */
    NETDEV_PTZ_CRUISEADDSTOP        = 0x1006,       /*   Stop adding preset to route */
#endif

    NETDEV_PTZ_INVALID

} NETDEV_PTZ_E;

/**
 * @enum tagNETDEVPtzPresetCmd
 * @brief   PTZ preset operation commands Enumeration Definition
 * @attention  None
 */
typedef enum tagNETDEVPtzPresetCmd
{
    NETDEV_PTZ_SET_PRESET   = 0,            /*   Set preset */
    NETDEV_PTZ_CLE_PRESET   = 1,            /*   Clear preset */
    NETDEV_PTZ_GOTO_PRESET  = 2             /*   Go to preset */
}NETDEV_PTZ_PRESETCMD_E;

/**
 * @enum tagNETDEVPTZCruiseCmd
 * @brief   PTZ patrol operation commands Enumeration Definition
 * @attention  None
 */
typedef enum tagNETDEVPTZCruiseCmd
{
    NETDEV_PTZ_ADD_CRUISE      = 0,         /*    Add patrol route */
    NETDEV_PTZ_MODIFY_CRUISE   = 1,         /*   Edit patrol route */
    NETDEV_PTZ_DEL_CRUISE      = 2,         /*   Delete patrol route */
    NETDEV_PTZ_RUN_CRUISE      = 3,         /*   Start patrol */
    NETDEV_PTZ_STOP_CRUISE     = 4          /*   Stop patrol */
}NETDEV_PTZ_CRUISECMD_E;

/**
 * @enum tagNETDEVPlayControl
 * @brief   Playback control commands Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVPlayControl
{
    NETDEV_PLAY_CTRL_PLAY            = 0,           /*   Play */
    NETDEV_PLAY_CTRL_PAUSE           = 1,           /*   Pause */
    NETDEV_PLAY_CTRL_RESUME          = 2,           /*   Resume */
    NETDEV_PLAY_CTRL_GETPLAYTIME     = 3,           /*   Obtain playing time */
    NETDEV_PLAY_CTRL_SETPLAYTIME     = 4,           /*   Configure playing time */
    NETDEV_PLAY_CTRL_GETPLAYSPEED    = 5,           /*   Obtain playing speed */
    NETDEV_PLAY_CTRL_SETPLAYSPEED    = 6,           /*   Configure playing speed */
    NETDEV_PLAY_CTRL_SINGLE_FRAME    = 7            /*   Configure single frame playing speed */
}NETDEV_VOD_PLAY_CTRL_E;

/**
 * @enum tagNETDEVVodPlayStatus
 * @brief .  Playback and download status Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVVodPlayStatus
{
    /**   Play status */
    NETDEV_PLAY_STATUS_16_BACKWARD          = 0,            /* 16  Backward at 16x speed */
    NETDEV_PLAY_STATUS_8_BACKWARD           = 1,            /* 8  Backward at 8x speed */
    NETDEV_PLAY_STATUS_4_BACKWARD           = 2,            /* 4  Backward at 4x speed */
    NETDEV_PLAY_STATUS_2_BACKWARD           = 3,            /* 2  Backward at 2x speed */
    NETDEV_PLAY_STATUS_1_BACKWARD           = 4,            /* 1  Backward at normal speed */
    NETDEV_PLAY_STATUS_HALF_BACKWARD        = 5,            /* 1/2  Backward at 1/2 speed */
    NETDEV_PLAY_STATUS_QUARTER_BACKWARD     = 6,            /* 1/4  Backward at 1/4 speed */
    NETDEV_PLAY_STATUS_QUARTER_FORWARD      = 7,            /* 1/4  Play at 1/4 speed */
    NETDEV_PLAY_STATUS_HALF_FORWARD         = 8,            /* 1/2  Play at 1/2 speed */
    NETDEV_PLAY_STATUS_1_FORWARD            = 9,            /* 1  Forward at normal speed */
    NETDEV_PLAY_STATUS_2_FORWARD            = 10,           /* 2  Forward at 2x speed */
    NETDEV_PLAY_STATUS_4_FORWARD            = 11,           /* 4  Forward at 4x speed */
    NETDEV_PLAY_STATUS_8_FORWARD            = 12,           /* 8  Forward at 8x speed */
    NETDEV_PLAY_STATUS_16_FORWARD           = 13,           /* 16  Forward at 16x speed */
    NETDEV_PLAY_STATUS_2_FORWARD_IFRAME     = 14,           /* 2(I) Forward at 2x speed(I frame) */
    NETDEV_PLAY_STATUS_4_FORWARD_IFRAME     = 15,           /* 4(I) Forward at 4x speed(I frame) */
    NETDEV_PLAY_STATUS_8_FORWARD_IFRAME     = 16,           /* 8(I) Forward at 8x speed(I frame) */
    NETDEV_PLAY_STATUS_16_FORWARD_IFRAME    = 17,           /* 16(I) Forward at 16x speed(I frame) */
    NETDEV_PLAY_STATUS_2_BACKWARD_IFRAME    = 18,           /* 2(I) Backward at 2x speed(I frame) */
    NETDEV_PLAY_STATUS_4_BACKWARD_IFRAME    = 19,           /* 4(I) Backward at 4x speed(I frame) */
    NETDEV_PLAY_STATUS_8_BACKWARD_IFRAME    = 20,           /* 8(I) Backward at 8x speed(I frame) */
    NETDEV_PLAY_STATUS_16_BACKWARD_IFRAME   = 21,           /* 16(I) Backward at 16x speed(I frame) */
    NETDEV_PLAY_STATUS_INTELLIGENT_FORWARD  = 22,           /*  Intelligent forward */
    NETDEV_PLAY_STATUS_1_FRAME_FORWD        = 23,           /*   Forward at 1 frame speed */
    NETDEV_PLAY_STATUS_1_FRAME_BACK         = 24,           /*  Backward at 1 frame speed */

    NETDEV_PLAY_STATUS_INVALID
}NETDEV_VOD_PLAY_STATUS_E;

/**
 * @enum tagNETDEVDownloadSpeed
 * @brief   Recording download speed
 * @attention  None
 */
typedef enum tagNETDEVDownloadSpeed
{
    NETDEV_DOWNLOAD_SPEED_ONE           = 0,                /*   1x */
    NETDEV_DOWNLOAD_SPEED_TWO           = 1,                /*   2x */
    NETDEV_DOWNLOAD_SPEED_FOUR          = 2,                /*   4x */
    NETDEV_DOWNLOAD_SPEED_EIGHT         = 3,                /*   8x */
    NETDEV_DOWNLOAD_SPEED_TWO_IFRAME    = 4,                /*   I2x */
    NETDEV_DOWNLOAD_SPEED_FOUR_IFRAME   = 5,                /*   I4x */
    NETDEV_DOWNLOAD_SPEED_EIGHT_IFRAME  = 6,                /*   I8x */
    NETDEV_DOWNLOAD_SPEED_HALF          = 7                 /*   1/2x */
}NETDEV_E_DOWNLOAD_SPEED_E;

/**
 * @enum tagNETDEVStoreType
 * @brief   Recording storage type Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVStoreType
{
    NETDEV_TYPE_STORE_TYPE_ALL                  = 0,            /*   All */

    NETDEV_EVENT_STORE_TYPE_MOTIONDETECTION     = 4,            /*   Motion detection */
    NETDEV_EVENT_STORE_TYPE_DIGITALINPUT        = 5,            /*   Digital input */
    NETDEV_EVENT_STORE_TYPE_VIDEOLOSS           = 7,            /*   Video loss */

    NETDEV_TYPE_STORE_TYPE_INVALID              = 0xFF          /*   Invalid value */
}NETDEV_PLAN_STORE_TYPE_E;

/**
 * @enum tagNETDEVException
 * @brief   Exception callback message types Enumeration definition 
 * @attention  None
 */
typedef enum tagNETDEVException
{
    /*   Playback exceptions report 300~399 */
    NETDEV_EXCEPTION_REPORT_VOD_END             = 300,          /*   Playback ended*/
    NETDEV_EXCEPTION_REPORT_VOD_ABEND           = 301,          /*   Playback exception occured */
    NETDEV_EXCEPTION_REPORT_BACKUP_END          = 302,          /*   Backup ended */
    NETDEV_EXCEPTION_REPORT_BACKUP_DISC_OUT     = 303,          /*   Disk removed */
    NETDEV_EXCEPTION_REPORT_BACKUP_DISC_FULL    = 304,          /*   Disk full */
    NETDEV_EXCEPTION_REPORT_BACKUP_ABEND        = 305,          /*    Backup failure caused by other reasons */

    NETDEV_EXCEPTION_EXCHANGE                   = 0x8000,       /*   Exception occurred during user interaction (keep-alive timeout) */

    NETDEV_EXCEPTION_REPORT_INVALID             = 0xFFFF        /*   Invalid value */
}NETDEV_EXCEPTION_TYPE_E;

/**
 * @enum tagNETDEVAlarmTypeEn
 * @brief    Alarm configuration operation Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVAlarmTypeEn
{
    /*   Recoverable alarms */
    NETDEV_ALARM_MOVE_DETECT                        = 1,            /*   Motion detection alarm */
    NETDEV_ALARM_VIDEO_LOST                         = 2,            /*   Video loss alarm */
    NETDEV_ALARM_VIDEO_TAMPER_DETECT                = 3,            /*   Tampering detection alarm */
    NETDEV_ALARM_INPUT_SWITCH                       = 4,            /*   boolean input alarm */
    NETDEV_ALARM_TEMPERATURE_HIGH                   = 5,            /*   High temperature alarm */
    NETDEV_ALARM_TEMPERATURE_LOW                    = 6,            /*   Low temperature alarm */
    NETDEV_ALARM_AUDIO_DETECT                       = 7,            /*   Audio detection alarm */
    NETDEV_ALARM_DISK_ABNORMAL                      = 8,            /*  Disk abnormal */
    NETDEV_ALARM_DISK_OFFLINE                       = 9,            /*  Disk online */
    NETDEV_ALARM_DISK_ONLINE                        = 10,           /*  Disk online */
    NETDEV_ALARM_DISK_STORAGE_WILL_FULL             = 11,           /*  Disk StorageGoingfull */
    NETDEV_ALARM_DISK_STORAGE_IS_FULL               = 12,           /*  StorageIsfull */
    NETDEV_ALARM_DISK_RAID_DISABLED                 = 13,           /*  RAIDDisabled */
    NETDEV_ALARM_DISK_RAID_DEGRADED                 = 14,           /*  RAIDDegraded */
    NETDEV_ALARM_DISK_RAID_RECOVERED                = 15,           /*  RAIDDegraded */

    /* NVR  Status report of NVR and access device 100~199 */
    NETDEV_ALARM_REPORT_DEV_ONLINE                  = 100,          /*   Device online */
    NETDEV_ALARM_REPORT_DEV_OFFLINE                 = 101,          /*   Device offline */
    NETDEV_ALARM_REPORT_DEV_VIDEO_LOSS              = 102,          /*   Video loss */
    NETDEV_ALARM_REPORT_DEV_VIDEO_LOSS_RECOVER      = 103,          /*   Video loss recover */
    NETDEV_ALARM_REPORT_DEV_REBOOT                  = 104,          /*   Device restart */
    NETDEV_ALARM_REPORT_DEV_SERVICE_REBOOT          = 105,          /*   Service restart */
    NETDEV_ALARM_REPORT_DEV_DELETE_CHL              = 106,          /*   Delete channel */

    /*   Live view exception report 200~299 */
    NETDEV_ALARM_NET_FAILED                         = 200,          /*  Network error */
    NETDEV_ALARM_NET_TIMEOUT                        = 201,          /*  Network timeout */
    NETDEV_ALARM_SHAKE_FAILED                       = 202,          /*  Interaction error */
    NETDEV_ALARM_STREAMNUM_FULL                     = 203,          /*  Stream full */
    NETDEV_ALARM_STREAM_THIRDSTOP                   = 204,          /*  Third party stream stopped */
    NETDEV_ALARM_FILE_END                           = 205,          /*  File ended */

    /* 24  Valid alarms within 24 hours without arming schedule */
    NETDEV_ALARM_ALLTIME_FLAG_START                 = 400,          /*   Start marker of alarm without arming schedule */
    NETDEV_ALARM_STOR_ERR                           = 401,          /*   Storage error */
    NETDEV_ALARM_STOR_DISOBEY_PLAN                  = 402,          /*   Not stored as planned */

    /*   Unrecoverable alarms */
    NETDEV_ALARM_NO_RECOVER_FLAG_START              = 500,          /*   Start marker of unrecoverable alarm */
    NETDEV_ALARM_DISK_ERROR                         = 501,          /*   Disk error */
    NETDEV_ALARM_ILLEGAL_ACCESS                     = 502,          /*   Illegal access */
    NETDEV_ALARM_LINE_CROSS                         = 503,          /*   Line cross */
    NETDEV_ALARM_OBJECTS_INSIDE                     = 504,          /*   Objects inside */
    NETDEV_ALARM_FACE_RECOGNIZE                     = 505,          /*   Face recognize */
    NETDEV_ALARM_IMAGE_BLURRY                       = 506,          /*   Image blurry */
    NETDEV_ALARM_SCENE_CHANGE                       = 507,          /*   Scene change */
    NETDEV_ALARM_SMART_TRACK                        = 508,          /*   Smart track */
    NETDEV_ALARM_LOITERING_DETECTOR                 = 509,          /*   Loitering Detector */
    NETDEV_ALARM_ALLTIME_FLAG_END                   = 600,          /*   End marker of alarm without arming schedule */

    /*   Alarm recover */
    NETDEV_ALARM_RECOVER_BASE                       = 1000,         /*   Alarm recover base */
    NETDEV_ALARM_MOVE_DETECT_RECOVER                = 1001,         /*   Motion detection alarm recover */
    NETDEV_ALARM_VIDEO_LOST_RECOVER                 = 1002,         /*   Video loss alarm recover */
    NETDEV_ALARM_VIDEO_TAMPER_RECOVER               = 1003,         /*   Tampering detection alarm recover */
    NETDEV_ALARM_INPUT_SWITCH_RECOVER               = 1004,         /*   Boolean input alarm recover */
    NETDEV_ALARM_TEMPERATURE_RECOVER                = 1005,         /*   Temperature alarm recover */
    NETDEV_ALARM_AUDIO_DETECT_RECOVER               = 1007,         /*   Audio detection alarm recover */
    NETDEV_ALARM_DISK_ABNORMAL_RECOVER              = 1008,         /*  Disk abnormal recover */
    NETDEV_ALARM_DISK_OFFLINE_RECOVER               = 1009,         /*  Disk online recover */
    NETDEV_ALARM_DISK_ONLINE_RECOVER                = 1010,         /*  Disk online recover */
    NETDEV_ALARM_DISK_STORAGE_WILL_FULL_RECOVER     = 1011,         /*  Disk StorageGoingfull recover */
    NETDEV_ALARM_DISK_STORAGE_IS_FULL_RECOVER       = 1012,         /*  StorageIsfull recover */
    NETDEV_ALARM_DISK_RAID_DISABLED_RECOVER         = 1013,         /*  RAIDDisabled recover */
    NETDEV_ALARM_DISK_RAID_DEGRADED_RECOVER         = 1014,         /*  RAIDDegraded recover */

    NETDEV_ALARM_STOR_ERR_RECOVER                   = 1201,         /*   Storage error recover */
    NETDEV_ALARM_STOR_DISOBEY_PLAN_RECOVER          = 1202,         /*   Not stored as planned recover */

    NETDEV_ALARM_IMAGE_BLURRY_RECOVER               = 1506,         /*   Image blurry recover */
    NETDEV_ALARM_SMART_TRACK_RECOVER                = 1508,         /*   Smart track recover */

    NETDEV_ALARM_INVALID                            = 0xFFFF        /*   Invalid value */
}NETDEV_ALARM_TYPE_E;

/**
 * @enum tagNETDEVLogMainType
 * @brief   Major types of logs Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVLogMainType
{
    NETDEV_LOG_MAIN_TYPE_ALL                    = 0,               /*   Logs of all types */
    NETDEV_LOG_MAIN_TYPE_ALARM                  = 1,               /*   Alarms */
    NETDEV_LOG_MAIN_TYPE_EXCEPTION              = 2,               /*   Exceptions */
    NETDEV_LOG_MAIN_TYPE_OPERATION              = 3,               /*   Operations */
    NETDEV_LOG_MAIN_TYPE_MESSAGE                = 4,               /*   Messages */

    NETDEV_LOG_MAIN_TYPE_INVALID                = 0xFFFF            /*   Invalid value */
}NETDEV_LOG_MAIN_TYPE_E;

/**
 * @enum tagNETDEVLogSubType
 * @brief ID  Minor type IDs of logs Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVLogSubType
{
    NETDEV_LOG_ALL_SUB_TYPES                     = 0x0101,          /*   All information logs */

    /*   Information logs */
    NETDEV_LOG_MSG_HDD_INFO                     = 300,              /*   HDD information */
    NETDEV_LOG_MSG_SMART_INFO                   = 301,              /*   S.M.A.R.T information */
    NETDEV_LOG_MSG_REC_OVERDUE                  = 302,              /*   Expired recording deletion */
    NETDEV_LOG_MSG_PIC_REC_OVERDUE              = 303,              /*   Expired image deletion */

    /*   notification logs */
    NETDEV_LOG_NOTICE_IPC_ONLINE                = 310,              /*   Device online */
    NETDEV_LOG_NOTICE_IPC_OFFLINE               = 311,              /*   Device offline */
    NETDEV_LOG_NOTICE_ARRAY_RECOVER             = 312,              /*   arrayRecover */
    NETDEV_LOG_NOTICE_INIT_ARRARY               = 313,              /*   initialize Array */
    NETDEV_LOG_NOTICE_REBUILD_ARRARY            = 314,              /*   rebuild Array */
    NETDEV_LOG_NOTICE_POE_PORT_STATUS           = 315,              /*   poe Port Status */
    NETDEV_LOG_NOTICE_NETWORK_PORT_STATUS       = 316,              /*  network Port Status */
    NETDEV_LOG_NOTICE_DISK_ONLINE               = 317,              /*   Disk online */

    /* ID  Sub type log ID of alarm logs */
    NETDEV_LOG_ALARM_MOTION_DETECT              = 350,              /*   Motion detection alarm */
    NETDEV_LOG_ALARM_MOTION_DETECT_RESUME       = 351,              /*   Motion detection alarm recover */
    NETDEV_LOG_ALARM_VIDEO_LOST                 = 352,              /*   Video loss alarm */
    NETDEV_LOG_ALARM_VIDEO_LOST_RESUME          = 353,              /*   Video loss alarm recover */
    NETDEV_LOG_ALARM_VIDEO_TAMPER_DETECT        = 354,              /*   Tampering detection alarm */
    NETDEV_LOG_ALARM_VIDEO_TAMPER_RESUME        = 355,              /*   Tampering detection alarm recover */
    NETDEV_LOG_ALARM_INPUT_SW                   = 356,              /*   Boolean input alarm */
    NETDEV_LOG_ALARM_INPUT_SW_RESUME            = 357,              /*   Boolean input alarm recover */
    NETDEV_LOG_ALARM_IPC_ONLINE                 = 358,              /*   Device online */
    NETDEV_LOG_ALARM_IPC_OFFLINE                = 359,              /*   Device offline */
    
    NETDEV_LOG_ALARM_AUDIO_DETECTION_START      = 360,              /*   Audio detection start */
    NETDEV_LOG_ALARM_AUDIO_DETECTION_END        = 361,              /*   Audio detection end */
    NETDEV_LOG_ALARM_CROSS_LINE_DETECT          = 362,              /*   CrossLine detection */
    NETDEV_LOG_ALARM_FACE_DETECT                = 363,              /*   Face Detection */
    NETDEV_LOG_ALARM_INTRUSION_DETECT           = 364,              /*   Intrusion Detection */
    NETDEV_LOG_ALARM_POS                        = 365,              /*   POS Alarm */
    NETDEV_LOG_ALARM_IMAGETOOBLURRY_ON          = 366,              /*   Defocus detection started*/
    NETDEV_LOG_ALARM_IMAGETOOBLURRY_OFF         = 367,              /*   Defocus detection ended*/
    NETDEV_LOG_ALARM_GLOBAL_SCENE_CHANGE        = 368,              /*   Scene change detection*/
    NETDEV_LOG_ALARM_AUTO_TRACK_ON              = 369,              /*   Auto tracking started*/
    NETDEV_LOG_ALARM_AUTO_TRACK_OFF             = 370,              /*   Auto tracking ended*/

    /* ID  Sub type log ID of exception logs */
    NETDEV_LOG_EXCEP_DISK_ONLINE                = 400,              /*   Disk online */
    NETDEV_LOG_EXCEP_DISK_OFFLINE               = 401,              /*   Disk offline */
    NETDEV_LOG_EXCEP_DISK_ERR                   = 402,              /*   Disk exception */
    NETDEV_LOG_EXCEP_STOR_ERR                   = 403,              /*   Storage error */
    NETDEV_LOG_EXCEP_STOR_ERR_RECOVER           = 404,              /*   Storage error recover */
    NETDEV_LOG_EXCEP_STOR_DISOBEY_PLAN          = 405,              /*   Not stored as planned */
    NETDEV_LOG_EXCEP_STOR_DISOBEY_PLAN_RECOVER  = 406,              /*   Not stored as planned recover */
    NETDEV_LOG_EXCEP_ILLEGAL_ACCESS             = 407,              /*   Illegal access */
    NETDEV_LOG_EXCEP_IP_CONFLICT                = 408,              /*   IP address conflict */
    NETDEV_LOG_EXCEP_NET_BROKEN                 = 409,              /*   Network disconnection */
    NETDEV_LOG_EXCEP_PIC_REC_ERR                = 410,              /*   Failed to get captured image */
    NETDEV_LOG_EXCEP_VIDEO_EXCEPTION            = 411,              /*   Video input exception (for analog channel only) */
    NETDEV_LOG_EXCEP_VIDEO_MISMATCH             = 412,              /*   Video standards do not match */
    NETDEV_LOG_EXCEP_RESO_MISMATCH              = 413,              /*   Encoding resolution and front-end resolution do not match */
    NETDEV_LOG_EXCEP_TEMP_EXCE                  = 414,              /*   Temperature exception */
    NETDEV_LOG_EXCEP_RUNOUT_RECORD_SPACE        = 415,              /*   runOutOfRecordSpace */
    NETDEV_LOG_EXCEP_RUNOUT_IMAGE_SPACE         = 416,              /*   runOutOfImageSpace */
    NETDEV_LOG_EXCEP_OUT_RECORD_SPACE           = 417,              /*   recordSpaceUsedUp */
    NETDEV_LOG_EXCEP_OUT_IMAGE_SPACE            = 418,              /*   imageSpaceUsedUp */
    NETDEV_LOG_EXCEP_ANRIDISASSEMBLY            = 419,              /*   antiDisassembly Alarm */
    NETDEV_LOG_EXCEP_ANRIDISASSEMBLY_RECOVER    = 420,              /*  antiDisassembly AlarmClear*/
    NETDEV_LOG_EXCEP_ARRAY_DAMAGE               = 421,              /*   arrayDamage */
    NETDEV_LOG_EXCEP_ARRAY_DEGRADE              = 422,              /*   arrayDegrade */
    NETDEV_LOG_EXCEP_RECORD_SNAPSHOT_ABNOR      = 423,              /*   recordSnapshotAbnormal */
    NETDEV_LOG_EXCEP_NET_BROKEN_RECOVER         = 424,              /*   networkDisconnectClear */
    NETDEV_LOG_EXCEP_IP_CONFLICT_RECOVER        = 425,              /*   IP Conflict Clear */

    /* ID  Sub type log ID of operation logs */
    /*   Services */
    NETDEV_LOG_OPSET_LOGIN                      = 450,              /*   User login */
    NETDEV_LOG_OPSET_LOGOUT                     = 451,              /*   Log out */
    NETDEV_LOG_OPSET_USER_ADD                   = 452,              /*   Add user */
    NETDEV_LOG_OPSET_USER_DEL                   = 453,              /*   Delete user */
    NETDEV_LOG_OPSET_USER_MODIFY                = 454,              /*   Modify user */
    NETDEV_LOG_OPSET_START_REC                  = 455,              /*   Start recording */
    NETDEV_LOG_OPSET_STOP_REC                   = 456,              /*   Stop recording */
    NETDEV_LOG_OPSETR_PLAY_DOWNLOAD             = 457,              /*   Playback and download */
    NETDEV_LOG_OPSET_DOWNLOAD                   = 458,              /*   Download */
    NETDEV_LOG_OPSET_PTZCTRL                    = 459,              /*   PTZ control */
    NETDEV_LOG_OPSET_PREVIEW                    = 460,              /*   Live preview */
    NETDEV_LOG_OPSET_REC_TRACK_START            = 461,              /*   Start recording route */
    NETDEV_LOG_OPSET_REC_TRACK_STOP             = 462,              /*   Stop recording route */
    NETDEV_LOG_OPSET_START_TALKBACK             = 463,              /*   Start two-way audio */
    NETDEV_LOG_OPSET_STOP_TALKBACK              = 464,              /*   Stop two-way audio */
    NETDEV_LOG_OPSET_IPC_ADD                    = 465,              /*   Add IP camera */
    NETDEV_LOG_OPSET_IPC_DEL                    = 466,              /*   Delete IP camera */
    NETDEV_LOG_OPSET_IPC_SET                    = 467,              /*   Modify IP camera */
    NETDEV_LOG_OPSET_IPC_QUICK_ADD              = 468,              /*   quick Add Ipc*/
    NETDEV_LOG_OPSET_IPC_ADD_BY_NETWORK         = 469,              /*   add Ipc By Network */
    NETDEV_LOG_OPSET_IPC_MOD_IP                 = 470,              /*   modify Ipc Addr */

    /*   Configurations */
    NETDEV_LOG_OPSET_DEV_BAS_CFG                = 500,              /*   Basic device information */
    NETDEV_LOG_OPSET_TIME_CFG                   = 501,              /*   Device time */
    NETDEV_LOG_OPSET_SERIAL_CFG                 = 502,              /*   Device serial port */
    NETDEV_LOG_OPSET_CHL_BAS_CFG                = 503,              /*   Basic channel configuration */
    NETDEV_LOG_OPSET_CHL_NAME_CFG               = 504,              /*   Channel name configuration */
    NETDEV_LOG_OPSET_CHL_ENC_VIDEO              = 505,              /*   Video encoding configuration */
    NETDEV_LOG_OPSET_CHL_DIS_VIDEO              = 506,              /*   Video display configuration */
    NETDEV_LOG_OPSET_PTZ_CFG                    = 507,              /*   PTZ configuration */
    NETDEV_LOG_OPSET_CRUISE_CFG                 = 508,              /*   Patrol route configuration */
    NETDEV_LOG_OPSET_PRESET_CFG                 = 509,              /*   Preset configuration */
    NETDEV_LOG_OPSET_VIDPLAN_CFG                = 510,              /*   Recording schedule configuration */
    NETDEV_LOG_OPSET_MOTION_CFG                 = 511,              /*   Motion detection configuration */
    NETDEV_LOG_OPSET_VIDLOSS_CFG                = 512,              /*   Video loss configuration */
    NETDEV_LOG_OPSET_COVER_CFG                  = 513,              /*   Tampering detection configuration */
    NETDEV_LOG_OPSET_MASK_CFG                   = 514,              /*   Privacy mask configuration */
    NETDEV_LOG_OPSET_SCREEN_OSD_CFG             = 515,              /*   OSD overlay configuration */
    NETDEV_LOG_OPSET_ALARMIN_CFG                = 516,              /*   Alarm input configuration */
    NETDEV_LOG_OPSET_ALARMOUT_CFG               = 517,              /*   Alarm output configuration */
    NETDEV_LOG_OPSET_ALARMOUT_OPEN_MAN          = 518,              /* ,  Manually enable alarm output, GUI */
    NETDEV_LOG_OPSET_ALARMOUT_CLOSE_MAN         = 519,              /* ,  Manually disable alarm input, GUI */
    NETDEV_LOG_OPSET_ABNORMAL_CFG               = 520,              /*   Exception configuration */
    NETDEV_LOG_OPSET_HDD_CFG                    = 521,              /*   HDD configuration */
    NETDEV_LOG_OPSET_NET_IP_CFG                 = 522 ,             /*   TCP/IP configuration */
    NETDEV_LOG_OPSET_NET_PPPOE_CFG              = 523,              /*   PPPOE configuration */
    NETDEV_LOG_OPSET_NET_PORT_CFG               = 524,              /*   Port configuration */
    NETDEV_LOG_OPSET_NET_DDNS_CFG               = 525,              /*   DDNS configuration */
    NETDEV_ALARM_BANDWIDTH_CHANGE               = 526,              /*   Bandwidth change */
    NETDEV_LOG_OPSET_AUDIO_DETECT               = 527,              /*   searchExtendDisk */
    NETDEV_LOG_OPSET_SEARCH_EX_DISK             = 528,              /*   searchExtendDisk */
    NETDEV_LOG_OPSET_ADD_EX_DISK                = 529 ,             /*   addExtendDisk */
    NETDEV_LOG_OPSET_DEL_EX_DISK                = 530,              /*   deleteExtendDisk */
    NETDEV_LOG_OPSET_SET_EX_DISK                = 531,              /*   setExtendDisk */
    NETDEV_LOG_OPSET_LIVE_BY_MULTICAST          = 532,              /*   liveViewByMulticast */
    NETDEV_LOG_OPSET_BISC_DEV_INFO              = 533,              /*   setBasicDeviceInfo */
    NETDEV_LOG_OPSET_PREVIEW_CFG                = 534,              /*   SetPreviewOnNvr */
    NETDEV_LOG_OPSET_SET_EMAIL                  = 535,              /*   setEmail */
    NETDEV_LOG_OPSET_TEST_EMAIL                 = 536,              /*   testEmail */
    NETDEV_LOG_OPSET_SET_IPCONTROL              = 537,              /* IP  setIPControl */
    NETDEV_LOG_OPSET_PORT_MAP                   = 538 ,             /*   setPortMap */
    NETDEV_LOG_OPSET_ADD_TAG                    = 539,              /*   addTag */
    NETDEV_LOG_OPSET_DEL_TAG                    = 540,              /*   deleteTag */
    NETDEV_LOG_OPSET_MOD_TAG                    = 541,              /*   modifyTag */
    NETDEV_LOG_OPSET_LOCK_RECORD                = 542,              /*   lockRecord */
    NETDEV_LOG_OPSET_UNLOCK_RECORD              = 543,              /*   unlockRecord */
    NETDEV_LOG_OPSET_DDNS_UPDATE_SUCCESS        = 545,              /*   DDNSUpdateSuccess */
    NETDEV_LOG_OPSET_DDNS_INCORRECT_ID          = 546,              /*   DDNSUpdateFailedIncorrectUsernamePassword */
    NETDEV_LOG_OPSET_DDNS_DOMAIN_NAME_NOT_EXIST = 547,              /*   DDNSUpdateFailedDomainNameNotExist */
    NETDEV_LOG_OPSET_DDNS_UPDATE_FAIL           = 548,              /*   DDNSUpdateFailed */
    NETDEV_LOG_OPSET_HTTP_CFG                   = 549,              /*   setHttps */
    NETDEV_LOG_OPSET_IP_OFFLINE_ALARM_CFG       = 550,              /*   test DDNS Domain */
    NETDEV_LOG_OPSET_TELNET_CFG                 = 551,              /* Telnet  setTelnet */
    NETDEV_LOG_OPSET_TEST_DDNS_DOMAIN           = 552,              /* test DDNS Domain */
    NETDEV_LOG_OPSET_DDNS_DOMAIN_CONFLICT       = 553,              /*   DDNS Domain Invalid */
    NETDEV_LOG_OPSET_DDNS_DOMAIN_INVALID        = 554,              /*   set DDNS */
    NETDEV_LOG_OPSET_DEL_PRESET                 = 555,              /*   deletePreset */
    NETDEV_LOG_OPSET_PTZ_3D_POSITION            = 556,              /*   ptz 3DPosition */
    NETDEV_LOG_OPSET_SNAPSHOT_SCHEDULE_CFG      = 557,             /*   set Snapshot Schedule */
    NETDEV_LOG_OPSET_IMAGE_UPLOAD_SCHEDULE_CFG  = 558,              /*   set Image Upload Schedule */
    NETDEV_LOG_OPSET_FTP_CFG                    = 559,              /*   set Ftp Server */
    NETDEV_LOG_OPSET_TEST_FTP_SERVER            = 560,              /*   test Ftp Server */
    NETDEV_LOG_OPSET_START_MANUAL_SNAPSHOT      = 561,              /*   startManualSnapshot */
    NETDEV_LOG_OPSET_CLOSE_MANUAL_SNAPSHOT      = 562,              /*   endManualSnapshot */
    NETDEV_LOG_OPSET_SNAPSHOT_CFG               = 563,              /*   setSnapshot */
    NETDEV_LOG_OPSET_ADD_HOLIDAY                = 564 ,             /*   addHoliday */
    NETDEV_LOG_OPSET_DEL_HOLIDAY                = 565,              /*   deleteHoliday */
    NETDEV_LOG_OPSET_MOD_HOLIDAY                = 566,              /*   modifyHoliday */
    NETDEV_LOG_OPSET_ONOFF_HOLIDAY              = 567,              /* /  enableDisableHoliday */
    NETDEV_LOG_OPSET_ALLOCATE_SPACE             = 568,              /*   allocateSpace */
    NETDEV_LOG_OPSET_HDD_FULL_POLICY_CFG        = 569,              /*   setHddFullPolicy */
    NETDEV_LOG_OPSET_AUDIO_STREAM_CFG           = 570,              /*   setAudioStream */
    NETDEV_LOG_OPSET_ARRAY_PROPERTY_CFG         = 571,              /*   setArrayProperty */
    NETDEV_LOG_OPSET_HOT_SPACE_DISK_CFG         = 572,              /*   setHotSpaceDisk */
    NETDEV_LOG_OPSET_CREAT_ARRAY                = 573,              /*   createArray */
    NETDEV_LOG_OPSET_ONE_CLICK_CREAT_ARRAY      = 574,              /*   oneClickCreateArray */
    NETDEV_LOG_OPSET_REBUILD_ARRAY              = 575,              /*   rebuildArray */
    NETDEV_LOG_OPSET_DEL_ARRAY                  = 576,              /*   deleteArray */
    NETDEV_LOG_OPSET_ENABLE_RAID                = 577,              /* RAID  enableRaid */
    NETDEV_LOG_OPSET_DISABLE_RAID               = 578,              /* RAID  disableRaid */
    NETDEV_LOG_OPSET_TEST_SMART                 = 579,              /* S.M.A.R.T  testSmart */
    NETDEV_LOG_OPSET_SMART_CFG                  = 580,              /* S.M.A.R.T  setSmart */
    NETDEV_LOG_OPSET_BAD_SECTOR_DETECT          = 581,              /*   badSectorDetect */
    NETDEV_LOG_OPSET_AUDIO_ALARM_DURATION       = 582,              /*   setAudioAlarmDuration */
    NETDEV_LOG_OPSET_CLR_AUDIO_ALARM            = 583,             /*   clearAudioAlarm */
    NETDEV_LOG_OPSET_IPC_TIME_SYNC_CFG          = 584,              /*   setIpcTimeSync */
    NETDEV_LOG_OPSET_ENABLE_DISK_GROUP          = 585,              /*   enableDiskGroup */
    NETDEV_LOG_OPSET_DISABLE_DISK_GRRUOP        = 586,              /*   disableDiskGroup */
    NETDEV_LOG_OPSET_ONVIF_AUTH_CFG             = 587,              /*   setOnvifAuth */
    NETDEV_LOG_OPSET_8021X_CFG                  = 588,              /*   set8021x */
    NETDEV_LOG_OPSET_ARP_PROTECTION_CFG         = 589,              /*   setArpProtection */
    NETDEV_LOG_OPSET_SMART_BASIC_INFO_CFG       = 590 ,             /*   setSmartBasicInfo */
    NETDEV_LOG_OPSET_CROSS_LINE_DETECT_CFG      = 591,              /*   setCrossLineDetection */
    NETDEV_LOG_OPSET_INSTRUSION_DETECT_CFG      = 592,              /*   setIntrusionDetection */
    NETDEV_LOG_OPSET_PEOPLE_COUNT_CFG           = 593,              /*   setPeopleCount */
    NETDEV_LOG_OPSET_FACE_DETECT_CFG            = 594,              /*   setFaceDetection */
    NETDEV_LOG_OPSET_FISHEYE_CFG                = 595,              /*   setFisheye */
    NETDEV_LOG_OPSET_CUSTOM_PROTOCOL_CFG        = 596,              /*   setCustomProtocol */
    NETDEV_LOG_OPSET_BEHAVIOR_SEARCH            = 597,              /*   behaviorSearch */
    NETDEV_LOG_OPSET_FACE_SEARCH                = 598,              /*   faceSearch */
    NETDEV_LOG_OPSET_PEOPLE_COUNT               = 599,              /*   peopleCount */
        
    /*  Maintenance */
    NETDEV_LOG_OPSET_START_DVR                  = 600,              /*   Start up*/
    NETDEV_LOG_OPSET_STOP_DVR                   = 601,              /*   Shut down */
    NETDEV_LOG_OPSET_REBOOT_DVR                 = 602,              /*   Restart device */
    NETDEV_LOG_OPSET_UPGRADE                    = 603,              /*   Version upgrade */
    NETDEV_LOG_OPSET_LOGFILE_EXPORT             = 604,              /*   Export log files */
    NETDEV_LOG_OPSET_CFGFILE_EXPORT             = 605,              /*   Export configuration files */
    NETDEV_LOG_OPSET_CFGFILE_IMPORT             = 606,              /*   Import configuration files */
    NETDEV_LOG_OPSET_CONF_SIMPLE_INIT           = 607,              /*   Export configuration files */
    NETDEV_LOG_OPSET_CONF_ALL_INIT              = 608,               /*   Restore to factory settings */

    NETDEV_LOG_OPSET_VCA_BACKUP                 = 700,              /*   vcaBackup */
    NETDEV_LOG_OPSET_3G4G_CFG                   = 701,              /* 3G/4G  set3g4g */
    NETDEV_LOG_OPSET_MOUNT_EXTENDED_DISK        = 702,              /*  Mount extended disk*/
    NETDEV_LOG_OPSET_UNMOUNT_EXTENDED_DISK      = 703,              /*  Unmount extended disk*/
    NETDEV_LOG_OPSET_FORCE_USER_OFFLINE         = 704,              /*  Force user off line*/

    NETDEV_LOG_OPSET_AUTO_FUNCTION              = 709,              /*   autoFunction */
    NETDEV_LOG_OPSET_IPC_UPRAGDE                = 710,              /*   ipcUpgrade */
    NETDEV_LOG_OPSET_RESTORE_IPC_DEFAULTS       = 711,              /*   restoreIpcDefaults */
    NETDEV_LOG_OPSET_ADD_TRANSACTION            = 712,              /*   addTransaction */
    NETDEV_LOG_OPSET_MOD_TRANSACTION            = 713,              /*   modifyTransaction */
    NETDEV_LOG_OPSET_DEL_TRANSACTION            = 714,              /*   deleteTransaction */
    NETDEV_LOG_OPSET_POS_OSD                    = 715,              /*   setPosOsd */
    NETDEV_LOG_OPSET_ADD_HOT_SPACE_DEV          = 716,              /*   addHotSpaceDevice */
    NETDEV_LOG_OPSET_DEL_HOT_SPACE_DEV          = 717,              /*   deleteHotSpaceDevice */
    NETDEV_LOG_OPSET_MOD_HOT_SPACE_DEV          = 718,              /*   modifyHotSpaceDevice */
    NETDEV_LOG_OPSET_DEL_WORK_DEV               = 719,              /*   deleteWorkDevice */
    NETDEV_LOG_OPSET_WORKMODE_TO_NORMAL_CFG     = 720,              /*   SetWorkModeToNormal */
    NETDEV_LOG_OPSET_WORKMODE_TO_HOTSPACE_CFG   = 721,              /*   SetWorkModeToHotSpace */
    NETDEV_LOG_OPSET_AUTO_GUARD_CFG             = 723,              /*   setAutoGuard */
    NETDEV_LOG_OPSET_MULTICAST_CFG              = 724,              /*   SetMulticast */
    NETDEV_LOG_OPSET_DEFOCUS_DETECT_CFG         = 725,              /*  Set defocus detection*/
    NETDEV_LOG_OPSET_SCENECHANGE_CFG            = 726,              /*  Set scene change detection*/
    NETDEV_LOG_OPSET_AUTO_TRCAK_CFG             = 727,              /*  Set auto tracking*/
    NETDEV_LOG_OPSET_SORT_CAMERA_CFG            = 728,              /*  Sort camera*/
    NETDEV_LOG_OPSET_WATER_MARK_CFG             = 729              /*  Set watermark*/
}NETDEV_LOG_SUB_TYPE_E;

typedef enum tagNETDEVDeviceType
{
    NETDEV_DTYPE_UNKNOWN                        = 0,            /* Unknown type */
    NETDEV_DTYPE_IPC                            = 1,            /* IPC range */
    NETDEV_DTYPE_IPC_FISHEYE                    = 2,            /* IPC Certain fisheye camera models*/
    NETDEV_DTYPE_IPC_ECONOMIC_FISHEYE           = 3,            /* IPC Certain fisheye camera models*/
    NETDEV_DTYPE_NVR                            = 101,          /* NVR range */
    NETDEV_DTYPE_NVR_BACKUP                     = 102,          /* NVR  NVR back up */
    NETDEV_DTYPE_DC                             = 201,          /* DC range */
    NETDEV_DTYPE_DC_ADU                         = 202,          /* ADU range */
    NETDEV_DTYPE_EC                             = 301,          /* EC range */
    NETDEV_DTYPE_VMS                            = 501,          /* VMS range */

    NETDEV_DTYPE_INVALID                        = 0xFFFF        /*   Invalid value */
}NETDEV_DEVICETYPE_E;

/**
 * @enum tagNETDEVCfgCmd
 * @brief   Parameter configuration command words Enumeration definition
 * @attention  None
 */
typedef enum tagNETDEVCfgCmd
{
    NETDEV_GET_DEVICECFG                = 100,              /*  Get device information, see #NETDEV_DEVICE_BASICINFO_S */
    NETDEV_SET_DEVICECFG                = 101,              /*  Reserved */

    NETDEV_GET_NTPCFG                   = 110,              /*  Get NTP parameter, see #NETDEV_SYSTEM_NTP_INFO_S */
    NETDEV_SET_NTPCFG                   = 111,              /*  Set NTP parameter, see #NETDEV_SYSTEM_NTP_INFO_S */

    NETDEV_GET_STREAMCFG                = 120,              /*  Get video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_S */
    NETDEV_SET_STREAMCFG                = 121,              /*  Set video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_S */

    NETDEV_GET_STREAMCFG_EX             = 122,              /*  Get video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_LIST_S */
    NETDEV_SET_STREAMCFG_EX             = 123,              /*  Set video encoding parameter, see #NETDEV_VIDEO_STREAM_INFO_LIST_S */

    NETDEV_GET_VIDEOMODECFG             = 124,              
    NETDEV_SET_VIDEOMODECFG             = 125,              

    NETDEV_GET_PTZPRESETS               = 130,              /*  Get PTZ preset, see #NETDEV_PTZ_ALLPRESETS_S */

    NETDEV_GET_OSDCFG                   = 140,              /*   Get OSD configuration information, see #NETDEV_VIDEO_OSD_CFG_S */
    NETDEV_SET_OSDCFG                   = 141,              /*   Set OSD configuration information, see #NETDEV_VIDEO_OSD_CFG_S */

    NETDEV_GET_OSD_CONTENT_CFG          = 144,              /*   Get OSD configuration information, see #NETDEV_OSD_CONTENT_S */
    NETDEV_SET_OSD_CONTENT_CFG          = 145,              /*   Set OSD configuration information, see #NETDEV_OSD_CONTENT_S */
    NETDEV_GET_OSD_CONTENT_STYLE_CFG    = 146,              /*   Get OSD content style, see #NETDEV_OSD_CONTENT_STYLE_S */
    NETDEV_SET_OSD_CONTENT_STYLE_CFG    = 147,              /*   Set OSD content style, see #NETDEV_OSD_CONTENT_STYLE_S */

    NETDEV_GET_ALARM_OUTPUTCFG          = 150,              /*  Get boolean configuration information, see #NETDEV_ALARM_OUTPUT_LIST_S */
    NETDEV_SET_ALARM_OUTPUTCFG          = 151,              /*  Set boolean configuration information, see #NETDEV_ALARM_OUTPUT_LIST_S */
    NETDEV_TRIGGER_ALARM_OUTPUT         = 152,              /*  Trigger boolean, see #NETDEV_TRIGGER_ALARM_OUTPUT_S */
    NETDEV_GET_ALARM_INPUTCFG           = 153,              /*  Get the number of boolean inputs, see #NETDEV_ALARM_INPUT_LIST_S */

    NETDEV_GET_IMAGECFG                 = 160,              /*  Get image configuration information, see #NETDEV_IMAGE_SETTING_S */
    NETDEV_SET_IMAGECFG                 = 161,              /*  Set image configuration information, see #NETDEV_IMAGE_SETTING_S */

    NETDEV_GET_NETWORKCFG               = 170,              /*  Get network configuration information, see #NETDEV_NETWORKCFG_S */
    NETDEV_SET_NETWORKCFG               = 171,              /*  Set network configuration information, see #NETDEV_NETWORKCFG_S */

    NETDEV_GET_PRIVACYMASKCFG           = 180,              /*  Get privacy mask configuration information, see #NETDEV_PRIVACY_MASK_CFG_S */
    NETDEV_SET_PRIVACYMASKCFG           = 181,              /*  Set privacy mask configuration information, see #NETDEV_PRIVACY_MASK_CFG_S */
    NETDEV_DELETE_PRIVACYMASKCFG        = 182,              /*   Delete privacy mask configuration information */

    NETDEV_GET_TAMPERALARM              = 190,              /*  Get tamper alarm configuration information, see #NETDEV_TAMPER_ALARM_INFO_S */
    NETDEV_SET_TAMPERALARM              = 191,              /*  Set tamper alarm configuration information, see #NETDEV_TAMPER_ALARM_INFO_S */

    NETDEV_GET_MOTIONALARM              = 200,              /*  Get motion alarm configuration information, see #NETDEV_MOTION_ALARM_INFO_S */
    NETDEV_SET_MOTIONALARM              = 201,              /*  Set motion alarm configuration information, see #NETDEV_MOTION_ALARM_INFO_S */

    NETDEV_GET_DISKSINFO                = 210,              /*  Get disks information, see #NETDEV_GET_DISKS_INFO_S */

    NETDEV_GET_PTZSTATUS                = 220,              /*  Get PTZ status,  see #NETDEV_PTZ_STATUS_S  */

    NETDEV_GET_FOCUSINFO                = 230,              /*  Get focus info, see #NETDEV_FOCUS_INFO_S */
    NETDEV_SET_FOCUSINFO                = 231,              /*  Set focus info, see #NETDEV_FOCUS_INFO_S */

    NETDEV_GET_IRCUTFILTERINFO          = 240,              /*  Get IRcut filter info, see #NETDEV_IRCUT_FILTER_INFO_S */
    NETDEV_SET_IRCUTFILTERINFO          = 241,              /*  Set IRcut filter info, see #NETDEV_IRCUT_FILTER_INFO_S */

    NETDEV_GET_DEFOGGINGINFO            = 250,              /*  Get defogging info, see #NETDEV_DEFOGGING_INFO_S */
    NETDEV_SET_DEFOGGINGINFO            = 251,              /*  Set defogging info, see #NETDEV_DEFOGGING_INFO_S */

    NETDEV_CFG_INVALID                  = 0xFFFF            /*   Invalid value */

}NETDEV_CONFIG_COMMAND_E;


/**
 * @enum tagNETDEVDateOSDFormateCap
 * @brief   OSD date format capabilities enumeration 
 * @attention  None
 */
typedef enum tagNETDEVDateOSDFormateCap
{
    NETDEV_OSD_DATE_FORMAT_CAP_MD_YYYY          = 0,        /* M/d/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_MMDD_YYYY        = 1,        /* MM/dd/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_DDMM_YYYY        = 2,        /* dd/MM/yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_YYYY_MMDD        = 3,        /* yyyy/MM/dd */
    NETDEV_OSD_DATE_FORMAT_CAP_YYYYMMDDB        = 4,        /* yyyy-MM-dd */
    NETDEV_OSD_DATE_FORMAT_CAP_XX_MMDD_YYYY     = 5,        /* dddd, MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_MMMMDD_YYYY      = 6,        /* MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_CAP_DDMMMM_YYYY      = 7         /* dd MMMM, yyyy */
}NETDEV_OSD_DATE_FORMAT_CAP_E;

/**
 * @enum tagNETDEVTimeOSDFormateCap
 * @brief OSD OSD time format capabilities enumeration
 * @attention  None
 */
typedef enum tagNETDEVTimeOSDFormateCap
{
    NETDEV_OSD_TIME_FORMAT_CAP_HHMMSS = 0,                  /* HH:mm:ss */
    NETDEV_OSD_TIME_FORMAT_CAP_HH_MM_SS_PM                  /* hh:mm:ss tt */
}NETDEV_OSD_TIME_FORMAT_CAP_E;

/**
 * @enum tagNETDEVBooleanMode
 * @brief  Boolean input operation mode
 * @attention  None
 */
typedef enum tagNETDEVBooleanMode
{
    NETDEV_BOOLEAN_MODE_OPEN   = 1,                         /*   Always open */
    NETDEV_BOOLEAN_MODE_CLOSE  = 2,                         /*   Always closed */
    NETDEV_BOOLEAN_MODE_INVALID
}NETDEV_BOOLEAN_MODE_E;

/**
 * @enum tagNETDEVTimeOSDFormateCap
 * @brief  Boolean input operation mode
 * @attention  None
 */
typedef enum tagNETDEVRelayOutPutState
{
    NETDEV_BOOLEAN_STATUS_ACTIVE    = 0,                /*   Triggered */
    NETDEV_BOOLEAN_STATUS_INACTIVE  = 1                 /*  Not triggered */
}NETDEV_RELAYOUTPUT_STATE_E;

/**
* @enum tagNETDEVMediaDataFormat
* @brief 
* @attention 
*/
typedef enum tagNETDEVMediaDataFormat
{
    NETDEV_MEDIA_DATA_TS            = 0,            /* TS */
    NETDEV_MEDIA_DATA_RTP_ES        = 3             /* RTP + ES */
}NETDEV_MEDIA_DATA_FORMAT_E;

/**
* @enum tagNETDEVProtocolType
* @brief 
* @attention 
*/
typedef enum tagNETDEVProtocolType
{
    NETDEV_PROTOCOL_TYPE_HTTP  = 0,
    NETDEV_PROTOCOL_TYPE_HTTPS = 1,
    NETDEV_PROTOCOL_TYPE_RTSP  = 2
}NETDEV_PROTOCOL_TYPE_E;

/**
* @enum tagNETDEVTTimeZone
* @brief  Time Zone
* @attention  None
*/
typedef enum tagNETDEVTimeZone
{
    NETDEV_TIME_ZONE_W1200 = 0,              /* W12 */
    NETDEV_TIME_ZONE_W1100 = 1,              /* W11 */
    NETDEV_TIME_ZONE_W1000 = 2,              /* W10 */
    NETDEV_TIME_ZONE_W0900 = 3,              /* W9 */
    NETDEV_TIME_ZONE_W0800 = 4,              /* W8 */
    NETDEV_TIME_ZONE_W0700 = 5,              /* W7 */
    NETDEV_TIME_ZONE_W0600 = 6,              /* W6 */
    NETDEV_TIME_ZONE_W0500 = 7,              /* W5 */
    NETDEV_TIME_ZONE_W0430 = 8,              /* W4:30 */
    NETDEV_TIME_ZONE_W0400 = 9,              /* W4 */
    NETDEV_TIME_ZONE_W0330 = 10,             /* W3:30 */
    NETDEV_TIME_ZONE_W0300 = 11,             /* W3 */
    NETDEV_TIME_ZONE_W0200 = 12,             /* W2 */
    NETDEV_TIME_ZONE_W0100 = 13,             /* W1 */
    NETDEV_TIME_ZONE_0000  = 14,             /* W0 */
    NETDEV_TIME_ZONE_E0100 = 15,             /* E1 */
    NETDEV_TIME_ZONE_E0200 = 16,             /* E2 */
    NETDEV_TIME_ZONE_E0300 = 17,             /* E3 */
    NETDEV_TIME_ZONE_E0330 = 18,             /* E3:30 */
    NETDEV_TIME_ZONE_E0400 = 19,             /* E4 */
    NETDEV_TIME_ZONE_E0430 = 20,             /* E4:30 */
    NETDEV_TIME_ZONE_E0500 = 21,             /* E5 */
    NETDEV_TIME_ZONE_E0530 = 22,             /* E5:30 */
    NETDEV_TIME_ZONE_E0545 = 23,             /* E5:45 */
    NETDEV_TIME_ZONE_E0600 = 24,             /* E6 */
    NETDEV_TIME_ZONE_E0630 = 25,             /* E6:30 */
    NETDEV_TIME_ZONE_E0700 = 26,             /* E7 */
    NETDEV_TIME_ZONE_E0800 = 27,             /* E8 */
    NETDEV_TIME_ZONE_E0900 = 28,             /* E9 */
    NETDEV_TIME_ZONE_E0930 = 29,             /* E9:30 */
    NETDEV_TIME_ZONE_E1000 = 30,             /* E10 */
    NETDEV_TIME_ZONE_E1100 = 31,             /* E11 */
    NETDEV_TIME_ZONE_E1200 = 32,             /* E12 */
    NETDEV_TIME_ZONE_E1300 = 33,             /* E13 */

    NETDEV_TIME_ZONE_INVALID = 0xFF          /* Invalid value */
}NETDEV_TIME_ZONE_E;

/**
* @enum  tagNetDEVDayInWeek
* @brief Week emnu
* @attention 
*/
typedef enum tagNetDEVDayInWeek
{
    NETDEV_WEEK_SUNDAY                  = 0,                  /*   Sunday */
    NETDEV_WEEK_MONDAY                  = 1,                  /*   Monday */
    NETDEV_WEEK_TUESDAY                 = 2,                  /*   Tuesday */
    NETDEV_WEEK_WEDNESDAY               = 3,                  /*   Wednesday */
    NETDEV_WEEK_THURSDAY                = 4,                  /*   Thursday */
    NETDEV_WEEK_FRIDAY                  = 5,                  /*   Friday */
    NETDEV_WEEK_SATURDAY                = 6,                  /*   Saturday */
    NETDEV_WEEK_INVALID               = 0xff                  /*  Invalid value */
}NETDEV_DAY_IN_WEEK_E;

/**
* @enum  tagNetDEVDSTOffsetTime
* @brief  DST offset time
* @attention 
*/
typedef enum tagNetDEVDSTOffsetTime
{
    NETDEV_DST_OFFSET_TIME_30MIN                 = 30,          /* 30  30Minutes */
    NETDEV_DST_OFFSET_TIME_60MIN                 = 60,          /* 60  60Minutes */
    NETDEV_DST_OFFSET_TIME_90MIN                 = 90,          /* 90  90Minutes */
    NETDEV_DST_OFFSET_TIME_120MIN                = 120,         /* 120  120Minutes */
    NETDEV_DST_OFFSET_TIME_INVALID               = 0xff         /*  Invalid value */
}NETDEV_DST_OFFSET_TIME;



/**
 * @enum tagNETDEVDiskWorkStatus
 * @brief  Disk work status 
 * @attention  None
 */
typedef enum tagNETDEVDiskWorkStatus
{
    NETDEV_DISK_WORK_STATUS_EMPTY       = 0,            /*  Empty */
    NETDEV_DISK_WORK_STATUS_UNFORMAT    = 1,            /*  Unformat */
    NETDEV_DISK_WORK_STATUS_FORMATING   = 2,            /*  Formating */
    NETDEV_DISK_WORK_STATUS_RUNNING     = 3,            /*  Running */
    NETDEV_DISK_WORK_STATUS_HIBERNATE   = 4,            /*  Hibernate */
    NETDEV_DISK_WORK_STATUS_ABNORMAL    = 5,            /*  Abnormal */
    NETDEV_DISK_WORK_STATUS_UNKNOWN     = 6,            /*  Unknown */

    NETDEV_DISK_WORK_STATUS_INVALID                     /*  Invalid value */
}NETDEV_DISK_WORK_STATUS_E;


/**
* @enum tagPictureFluency
* @brief  Picture fluency
* @attention 
*/
typedef enum tagNetDEVPictureFluency
{
    NETDEV_PICTURE_REAL                 = 0,                /*  Real-time first */
    NETDEV_PICTURE_FLUENCY              = 1,                /*  Fluency first */

    NETDEV_PICTURE_FLUENCY_INVALID      = 0xff              /*  Invalid value */
}NETDEV_PICTURE_FLUENCY_E;

/**
* @enum tagNETDEVPtzHomePositionCmd
* @brief   PTZ home position operation commands Enumeration Definition
* @attention  None
*/
typedef enum tagNETDEVPtzHomePositionCmd
{
    NETDEV_PTZ_SET_HOMEPOSITION   = 0,            /*   Set home position */
    NETDEV_PTZ_GOTO_HOMEPOSITION  = 1             /*   Go to home position */
}NETDEV_PTZ_HOMEPOSITIONCMD_E;

/**
* @enum tagNETDEVPTZMoveStatus
* @brief  PTZ Move status
* @attention  None
*/
typedef enum tagNETDEVPTZMoveStatus
{
    NETDEV_PTZ_MOVE_STATUS_IDLE     = 0,             /*  Free */
    NETDEV_PTZ_MOVE_STATUS_MOVING   = 1,             /*  Moving */

    NETDEV_PTZ_MOVE_STATUS_INVALID  = 0xff           /*  Invalid value */
}NETDEV_PTZ_MOVE_STATUS_E;

/**
 * @enum tagNETDEVIrCutFilterMode
 * @brief  IRCut filter mode
 * @attention  None
 */
typedef enum  tagNETDEVIrCutFilterMode
{
    NETDEV_IR_CUT_FILTER_ON     = 0,            /*  On */
    NETDEV_IR_CUT_FILTER_OFF    = 1,            /*  Off */
    NETDEV_IR_CUT_FILTER_AUTO   = 2             /*  Auto */
}NETDEV_IR_CUT_FILTER_MODE_E;

/**
 * @enum tagNETDEVDefoggingMode
 * @brief  Defogging mode
 * @attention  None
 */
typedef enum  tagNETDEVDefoggingMode
{
    NETDEV_DEFOGGING_ON = 0,            /*  On */
    NETDEV_DEFOGGING_OFF                /*  Off */
}NETDEV_DEFOGGING_MODE_E;

/**
 * @enum tagNETDEVFocusMode
 * @brief  Focus mode
 * @attention  None
 */
typedef enum tagNETDEVFocusMode
{
    NETDEV_FOCUS_AUTO           = 1,            /*  Auto */
    NETDEV_FOCUS_MANUAL         = 2             /*  Manual */
}NETDEV_FOCUS_MODE_E;

/**
 * @enum tagNETDEVFocusNearlimit
 * @brief  Focus near limit
 * @attention  None
 */
typedef enum tagNETDEVFocusNearlimit
{
    NETDEV_FOCUS_NEARLIMIT_10       = 1,            /* 10cm */
    NETDEV_FOCUS_NEARLIMIT_100      = 2,            /* 100cm */
    NETDEV_FOCUS_NEARLIMIT_300      = 3,            /* 300cm */
    NETDEV_FOCUS_NEARLIMIT_1000     = 4,            /* 1000cm */

    NETDEV_FOCUS_NEARLIMI_INVALID   = 0xff          /*   Invalid value */
}NETDEV_FOCUS_NEARLIMIT_E;

/**
* @enum tagNETDEVRecordType
* @brief  Record Type
* @attention 
*/
typedef enum tagNETDEVRecordType
{
    NETDEV_RECORD_TYPE_MANUAL  = 0,
    NETDEV_RECORD_TYPE_NORMAL = 1
}NETDEV_RECORD_TYPE_E;


/**
 * @enum tagNETDEVVideoPosition
 * @brief  Video Position
 * @attention  None
 */
typedef enum tagNETDEVVideoPosition
{
    NETDEV_POSITION_LOCAL       = 1,
    NETDEV_POSITION_CHANNEL     = 2,
    NETDEV_POSITION_INVALID
}NETDEV_VIDEO_POSITION_E;

/**
 * @enum tagNETDEVVideoStatus
 * @brief  Video Status
 * @attention  None
 */
typedef enum tagNETDEVVideoStatus
{
    NETDEV_VIDEO_NONE       = 0,        /*  No video */
    NETDEV_VIDEO_EVENT      = 1,        /*  Event video */
    NETDEV_VIDEO_NORMAL     = 2,        /*  Normal video */
    NETDEV_VIDEO_INVALID
}NETDEV_VIDEO_STATUS_E;


/**
* @enum tagNETDEVCapabilityCommond
* @brief  Device capability commond
* @attention 
*/
typedef enum tagNETDEVCapabilityCommond
{
    NETDEV_CAP_VIDEO_ENCODE         = 1,            /*  Video encoding capability. See # NETDEV_VIDEO_STREAM_CAP_S for reference*/
    NETDEV_CAP_OSD                  = 2,            /*  OSD parameter capability. See # NETDEV_OSD_CAP_S for reference*/
    NETDEV_CAP_SMART                = 3,            /*  Smart capability. See # NETDEV_SMART_CAP_S for reference */
    NETDEV_CAP_VIDEO_ENCODE_EX      = 4,            /*  Video encoding capability. See # NETDEV_VIDEO_STREAM_CAP_EX_S for reference */

    NETDEV_CAP_INVALID              = 0Xff
}NETDEV_CAPABILITY_COMMOND_E;

/**
* @enum tagNETDEVVideoEncodeType
* @brief 
* @attention 
*/
typedef enum tagNETDEVVideoEncodeType
{
    NETDEV_VIDEO_ENCODE_H264    = 1,
    NETDEV_VIDEO_ENCODE_MPEG4   = 2,
    NETDEV_VIDEO_ENCODE_JPEG    = 3,

    NETDEV_VIDEO_ENCODE_INVALID = 0XFF
}NETDEV_ENCODE_TYPE_E;



/**
* @enum tagNETDEVTrafficStatisticsType
* @brief  
* @attention  None
*/
typedef enum tagNETDEVTrafficStatisticsType
{
    NETDEV_TRAFFIC_STATISTICS_TYPE_IN   = 0,        /*  Statistics type : Enter */
    NETDEV_TRAFFIC_STATISTICS_TYPE_OUT  = 1,        /*  Statistics type : Exit */
    NETDEV_TRAFFIC_STATISTICS_TYPE_ALL  = 2,        /*  Statistics type : All */
    NETDEV_TRAFFIC_STATISTICS_TYPE_BUTT
}NETDEV_TRAFFIC_STATISTICS_TYPE_E;

/**
* @enum tagNETDEVPeoplecntType
* @brief  
* @attention  None
*/
typedef enum tagNETDEVFormType
{
    NETDEV_FORM_TYPE_DAY    = 0,            /*  Form type : Day */
    NETDEV_FORM_TYPE_WEEK   = 1,            /*  Form type : Week */
    NETDEV_FORM_TYPE_MONTH  = 2,            /*  Form type : Month */
    NETDEV_FORM_TYPE_YEAR   = 3,            /*  Form type : Year */
    NETDEV_FORM_TYPE_BUTT
}NETDEV_FORM_TYPE_E;

/**
* @enum tagNETDEVSmartEncodeMode
* @brief   Enumeration of smart image encoding mode
* @attention  None
*/
typedef enum tagNETDEVSmartEncodeMode
{
    NETDEV_SMART_ENCODE_MODE_OFF      = 0,      /*  Off */
    NETDEV_SMART_ENCODE_MODE_BASIC    = 1,      /*  Basic mode */
    NETDEV_SMART_ENCODE_MODE_ADVANCED           /*  Advanced mode */
}NETDEV_SMART_ENCODE_MODE_E;

/**
* @enum tagNETDEVBitRateType
* @brief   Enumeration of bit rate mode
* @attention  None
*/
typedef enum tagNETDEVBitRateType
{
    NETDEV_BIT_RATE_TYPE_CBR      = 0,         /* CBR mode*/
    NETDEV_BIT_RATE_TYPE_VBR      = 1          /* VBR mode*/
}NETDEV_BIT_RATE_TYPE_E;

/**
* @enum tagNETDEVMainStreamType
* @brief   Enumeration of main stream type
* @attention  None
*/
typedef enum tagNETDEVMainStreamType
{
    NETDEV_MAIN_STREAM_TYPE_TIME     = 0,      /*  Scheduled main stream*/
    NETDEV_MAIN_STREAM_TYPE_EVENT    = 1       /*  Event main stream*/
}NETDEV_MAIN_STREAM_TYPE_E;

/**
* @enum tagNETDEVGopType
* @brief GOP  Enumeration of GOP type
* @attention  None
*/
typedef enum tagNETDEVGopType
{
    NETDEV_GOP_TYPE_IP       = 0,      /* IP */
    NETDEV_GOP_TYPE_IBP      = 1,      /* IBP */
    NETDEV_GOP_TYPE_IBBP     = 2,      /* IBBP */
    NETDEV_GOP_TYPE_I        = 3       /* I */
}NETDEV_GOP_TYPE_E;

/**
* @enum tagNETDEVOSDContentType
* @brief OSD  Enumeration of content type
* @attention  None
*/
typedef enum tagNETDEVOSDContentType
{
    NETDEV_OSD_CONTENT_TYPE_NOTUSE                      = 0,                    /*  Not used*/
    NETDEV_OSD_CONTENT_TYPE_CUSTOM                      = 1,                    /*  Custom*/
    NETDEV_OSD_CONTENT_TYPE_DATE_AND_TIME               = 2,                    /*  Time and date*/
    NETDEV_OSD_CONTENT_TYPE_PTZ_CONTROLLER              = 3,                    /*  PTZ controller*/
    NETDEV_OSD_CONTENT_TYPE_PTZ_COORDINATES             = 4,                    /*  PTZ Coordinates*/
    NETDEV_OSD_CONTENT_TYPE_CRUISE                      = 5,                    /*  Patrol*/
    NETDEV_OSD_CONTENT_TYPE_ZOOM                        = 6,                    /*  Zoom*/
    NETDEV_OSD_CONTENT_TYPE_PRESET                      = 7,                    /*   Preset*/
    NETDEV_OSD_CONTENT_TYPE_ALARM_INFO                  = 8,                    /*  Alarm */
    NETDEV_OSD_CONTENT_TYPE_ENCODE                      = 9,                    /*  Encoding*/
    NETDEV_OSD_CONTENT_TYPE_SERIAL_PORT                 = 10,                   /*  Serial Port OSD*/
    NETDEV_OSD_CONTENT_TYPE_PTZ_ORIENTATION             = 11,                   /*  PZT direction*/
    NETDEV_OSD_CONTENT_TYPE_CHN_NAME                    = 12,                   /*  Channel name*/
    NETDEV_OSD_CONTENT_TYPE_DEBUG                       = 13,                   /*   Debug OSD*/
    NETDEV_OSD_CONTENT_TYPE_PEOPLE_COUNTING             = 14,                   /*  People counting OSD*/
    NETDEV_OSD_CONTENT_TYPE_NETWORK_PORT                = 15,                   /*  Network Port OSD*/
    NETDEV_OSD_CONTENT_TYPE_TIME                        = 16,                   /*  Time*/
    NETDEV_OSD_CONTENT_TYPE_DATE                        = 17,                   /*  Date*/
    NETDEV_OSD_CONTENT_TYPE_SMART_CONTENT               = 18,                   /*  Sensing OSD*/
    NETDEV_OSD_CONTENT_TYPE_BATTERY                     = 19,                   /*  Battery OSD*/
    NETDEV_OSD_CONTENT_TYPE_SCROLL_OSD                  = 20,                   /*  Scroll text OSD*/
    NETDEV_OSD_CONTENT_TYPE_PICTURE_OVERLAY             = 21,                   /* LOGO OSD */
    NETDEV_OSD_CONTENT_TYPE_MOTOR_VEHICLE_NUM           = 22,                   /*  Vehicle flow of LPR*/
    NETDEV_OSD_CONTENT_TYPE_NON_MOTOR_VEHICLE_NUM       = 23,                   /*  Non-vehicle flow of LPR*/
    NETDEV_OSD_CONTENT_TYPE_PEOPLE_NUM                  = 24,                   /*  Pedestrian flow of LPR*/
    NETDEV_OSD_CONTENT_TYPE_INFOOSD_NUM                 = 25                    /* INFOOSD Number of INFOOSDtype*/
}NETDEV_OSD_CONTENT_TYPE_E;

/**
 * @enum tagNETDEVDateOSDFormate
 * @brief   Enumeration of date format
 * @attention  None
 */
typedef enum tagNETDEVDateOSDFormate
{
    NETDEV_OSD_DATE_FORMAT_YYYY_MMDD                = 0,           /* yyyy-MM-dd */
    NETDEV_OSD_DATE_FORMAT_MMDD_YYYY                = 1,           /* MM-dd-yyyy */
    NETDEV_OSD_DATE_FORMAT_CHINESE_YYYY_MMDD        = 2,           /* yyyyMMdd yyyy/MM/dd*/
    NETDEV_OSD_DATE_FORMAT_CHINESE_MMDD_YYYY        = 3,           /* MMddyyyy MM/dd/yyyy*/
    NETDEV_OSD_DATE_FORMAT_CHINESE_YYY_MMDD_X       = 4,           /*  yyyyMMdd X dddd yyyy MM dd*/
    NETDEV_OSD_DATE_FORMAT_CHINESE_MMDD_YYYY_X      = 5,           /* MMddyyyy X dddd MM dd yyyy*/
    NETDEV_OSD_DATE_FORMAT_ENGLISH_DDMM_YYYY        = 100,         /* dd/MM/yyyy */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_MMDD_YYYY        = 101,         /* MM/dd/yyyy */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_DDMMMM_YYYY      = 102,         /* dd MMMM, yyyy */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_MMMMDD_YYYY      = 103,         /* MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_DDDDDDMMMM_YYYY  = 104,         /* dddd, dd MMMM, yyyy  */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_DDDDDDMMMM_DDYYYY = 105,        /* dddd, MMMM dd, yyyy */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_YYYY_MMDD        = 106,         /*  yyyy/MM/dd */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_YYYY_MMMMDD      = 107,         /*  yyyy, MMMM dd */
    NETDEV_OSD_DATE_FORMAT_ENGLISH_DDDDYY_MMDD      = 108         /*  dddd, yy, MM dd */
}NETDEV_OSD_DATE_FORMAT_E;

/**
 * @enum tagNETDEVTimeOSDFormate
 * @brief OSD Enumeration of OSD time format
 * @attention  None
 */
typedef enum tagNETDEVTimeOSDFormate
{
    NETDEV_OSD_TIME_FORMAT_HHMMSS         = 0,                  /* HH:mm:ss */
    NETDEV_OSD_TIME_FORMAT_HH_MM_SS_T     = 1,                  /* hh:mm:ss t.t. */
    NETDEV_OSD_TIME_FORMAT_HH_MM_SS_TT    = 2,                  /* hh:mm:ss tt */
    NETDEV_OSD_TIME_FORMAT_TT_HH_MM_SS    = 3,                  /*  tt hh:mm:ss */
    NETDEV_OSD_TIME_FORMAT_PM_HH_MM_SS    = 4,                  /*  hh:mm:ss  P.M. hh:mm:ss*/
    NETDEV_OSD_TIME_FORMAT_HH_MM_SS_XX    = 5,                  /* HH:mm:ss.xxx */
    NETDEV_OSD_TIME_FORMAT_HH_MM_SS_XX_TT = 6                   /* hh:mm:ss.xxx tt */

}NETDEV_OSD_TIME_FORMAT_E;

/**
 * @enum tagNETDEVOSDFontStyle
 * @brief OSD Enumeration of OSD font style
 * @attention  None
 */
typedef enum tagNETDEVOSDFontStyle
{
    NETDEV_OSD_FONT_STYLE_BACKGROUND = 0,                  /*  Background*/
    NETDEV_OSD_FONT_STYLE_STROKE     = 1,                  /*  Stroke*/
    NETDEV_OSD_FONT_STYLE_HOLLOW     = 2,                  /*  Hollow*/
    NETDEV_OSD_FONT_STYLE_NORMAL     = 3                   /*  Normal*/
}NETDEV_OSD_FONT_STYLE_E;

/**
 * @enum tagNETDEVOSDFontSize
 * @brief OSD Enumeration of OSD font size
 * @attention  None
 */
typedef enum tagNETDEVOSDFontSize
{
    NETDEV_OSD_FONT_SIZE_LARGE  = 0,                  /*  X-large*/
    NETDEV_OSD_FONT_SIZE_BIG    = 1,                  /*  Large*/
    NETDEV_OSD_FONT_SIZE_MEDIUM = 2,                  /*  Medium*/
    NETDEV_OSD_FONT_SIZE_SMALL  = 3                   /*  Small*/
}NETDEV_OSD_FONT_SIZE_E;

/**
 * @enum tagNETDEVOSDMinMargin
 * @brief OSD Enumeration of OSD font size
 * @attention  None
 */
typedef enum tagNETDEVOSDMinMargin
{
    NETDEV_OSD_MIN_MARGIN_NONE    = 0,               /*  None*/
    NETDEV_OSD_MIN_MARGIN_SINGLE  = 1,               /*  One char width*/
    NETDEV_OSD_MIN_MARGIN_DOUBLE  = 2                /*  Two char width*/
}NETDEV_OSD_MIN_MARGIN_E;

/**
 * @enum tagNETDEVOSDAlign
 * @brief OSD Enumeration of OSD align
 * @attention  None
 */
typedef enum tagNETDEVOSDAlign
{
    NETDEV_OSD_ALIGN_LEFT   = 0,               /*  Left*/
    NETDEV_OSD_ALIGN_RIGHT  = 1                /*  Right*/
}NETDEV_OSD_ALIGN_E;

/* END*************   Enumeration value *************************** */

/* BEGIN***********   Structure *********************************** */

/**
 * @struct tagNETDEVDeviceInfo
 * @brief   Device information Structure definition
 * @attention  None
 */
typedef struct tagNETDEVDeviceInfo
{
    INT32   dwDevType;                          /*   Device type, see enumeration #NETDEV_DEVICETYPE_E */
    INT16   wAlarmInPortNum;                    /*   Number of alarm inputs */
    INT16   wAlarmOutPortNum;                   /*   Number of alarm outputs */
    INT32   dwChannelNum;                       /*   Number of Channels */
    BYTE    byRes[48];                          /*   Reserved */
}NETDEV_DEVICE_INFO_S,*LPNETDEV_DEVICE_INFO_S;

/**
 * @struct tagNETDEVDeviceBasicInfo
 * @brief   Basic device information Structure definition
 * @attention  None
 */
typedef struct tagNETDEVDeviceBasicInfo
{ 
    CHAR szDevModel[NETDEV_LEN_64];                     /*   Device model */
    CHAR szSerialNum[NETDEV_LEN_64];                    /*   Hardware serial number */
    CHAR szFirmwareVersion[NETDEV_LEN_64];              /*   Software version */
    CHAR szMacAddress[NETDEV_LEN_64];                   /*   MAC address of IPv4 */
    CHAR szDeviceName[NETDEV_LEN_64];                   /*   Device name */
    BYTE byRes[448];                                    /*   Reserved */
}NETDEV_DEVICE_BASICINFO_S, *LPNETDEV_DEVICE_BASICINFO_S;

/**
 * @struct tagNETDEVNetworkInterfaces
 * @brief   Network configuration information
 * @attention  None
 */
typedef struct tagNETDEVNetworkInterfaces
{
    INT32   dwMTU;                              /*  MTU value */
    BOOL    bIPv4DHCP;                          /*  DHCP of IPv4 */
    CHAR    szIpv4Address[NETDEV_LEN_32];       /*  IP address of IPv4 */
    CHAR    szIPv4GateWay[NETDEV_LEN_32];       /*  Gateway of IPv4 */
    CHAR    szIPv4SubnetMask[NETDEV_LEN_32];    /*  Subnet mask of IPv4 */
    BYTE    byRes[480];                         /*   Reserved */
}NETDEV_NETWORKCFG_S, *LPNETDEV_NETWORKCFG_S;

/**
 * @struct tagSysemIPAddr
 * @brief   Address Structure definition 
 * @attention  None
 */
typedef struct tagSysemIPAddr
{
    INT32   eIPType;                            /* Protocol type, see enumeration #NETDEV_HOSTTYPE_E */
    CHAR    szIPAddr[NETDEV_LEN_132];           /* IP address */
}NETDEV_SYSTEM_IPADDR_S, *LPNETDEV_SYSTEM_IPADDR_S;

/**
 * @struct tagNETDEVSystemNTPInfo
 * @brief  NTP NTP parameter
 * @attention  None
 */
typedef struct tagNETDEVSystemNTPInfo
{
    BOOL bSupportDHCP;                      /* Support DHCP or not */
    NETDEV_SYSTEM_IPADDR_S stAddr;          /* NTP information */
}NETDEV_SYSTEM_NTP_INFO_S, *LPNETDEV_SYSTEM_NTP_INFO_S;

/**
 * @struct tagNETDEVPriviewInfo
 * @brief   Live view parameter Structure definition
 * @attention  None
 */
typedef struct tagNETDEVPriviewInfo
{
    INT32   dwChannelID;                    /* Channel ID */
    INT32   dwStreamType;                   /* Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E */
    INT32   dwLinkMode;                     /* Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                       /*  Play window handle */ 
    INT32   dwFluency;                      /* NETDEV_PICTURE_FLUENCY_E */
    BYTE    byRes[260];                     /*   Reserved */
}NETDEV_PREVIEWINFO_S, *LPNETDEV_PREVIEWINFO_S;

/**
 * @struct tagNETDEVVideoEffect
 * @brief   Live image information Structure definition
 * @attention 0-10,0-255 Gamma parameter range: 0-10, other parameters: 0-255
 */
typedef struct tagNETDEVVideoEffect
{
    INT32 dwContrast;                   /*   Contrast */
    INT32 dwBrightness;                 /*   Brightness */
    INT32 dwSaturation;                 /*   Saturation */
    INT32 dwHue;                        /*   Hue */
    INT32 dwGamma;                      /*   Gamma */
    BYTE  byRes[16];                    /*   Reserved */
}NETDEV_VIDEO_EFFECT_S, *LPNETDEV_VIDEO_EFFECT_S;

/**
 * @struct tagNETDEVImagingSetting
 * @brief      Device image settings Structure definition
 * @attention 0-255     parameter range: 0-255
 */
typedef struct tagNETDEVImagingSetting
{
    INT32 dwContrast;                   /*   Contrast */
    INT32 dwBrightness;                 /*   Brightness */
    INT32 dwSaturation;                 /*   Saturation */
    INT32 dwSharpness;                  /*   Sharpness */
    BYTE  byRes[252];                   /*   Reserved */
}NETDEV_IMAGE_SETTING_S, *LPNETDEV_IMAGE_SETTING_S;

/************  Playback services***********************************************/

/**
 * @struct tagNETDEVVodFile
 * @brief   Recording file Structure definition
 * @attention  None
 */
typedef struct tagNETDEVVodFile
{
    CHAR                        szFileName[NETDEV_LEN_64];      /*   Recording file name */
    NETDEV_PLAN_STORE_TYPE_E    enType;                         /*   Recording storage type */
    INT64                       tBeginTime;                     /*   Start time */
    INT64                       tEndTime;                       /*   End time */
}NETDEV_VOD_FILE_S, *LPNETDEV_VOD_FILE_S;

/**
 * @struct tagNETDEVFindCond
 * @brief   Recording query Structure definition
 *        . Query recording files according to file type and time
 * @attention  None
 */
typedef struct tagNETDEVFindCond
{
    CHAR    szFileName[NETDEV_LEN_64];      /*   Recording file name */
    INT32   dwChannelID;                    /*   Channel ID */
    INT32   dwStreamType;                   /*  Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E */
    INT32   dwFileType;                     /*   Recording storage type, see enumeration #NETDEV_PLAN_STORE_TYPE_E */
    INT64   tBeginTime;                     /*   Start time */
    INT64   tEndTime;                       /*   End time */
    BYTE    byRes[36];                      /*   Reserved */
}NETDEV_FILECOND_S, *LPNETDEV_FILECOND_S;

/**
 * @struct tagNETDEVFingData
 * @brief   Recording query data Structure definition
 *         Get the information of found files one by one
 * @attention  None
 */
typedef struct tagNETDEVFindData
{
    CHAR    szFileName[NETDEV_FILE_NAME_LEN];               /*   Recording file name */
    INT64   tBeginTime;                                     /*   Start time */
    INT64   tEndTime;                                       /*   End time */
    BYTE    byFileType;                                     /*   Recording storage type */
    BYTE    byRes[171];                                     /*   Reserved */
}NETDEV_FINDDATA_S,*LPNETDEV_FINDDATA_S;

/**
 * @struct tagNETDEVPlayBackInfo
 * @brief   Parameters of play back recordings by file name Structure definition
 * @attention  None
 */
typedef struct tagNETDEVPlayBackInfo
{
    char    szName[NETDEV_LEN_260];         /*   Playback control block name*/
    INT64   tBeginTime;                     /*   Playback start time */
    INT64   tEndTime;                       /*   Playback end time */
    INT32   dwLinkMode;                     /*   Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                       /*   Play window handle */
    INT32   dwFileType;                     /*   Recording storage type, see enumeration #NETDEV_PLAN_STORE_TYPE_E */
    INT32   dwDownloadSpeed;                /*   Download speed, see enumeration #NETDEV_E_DOWNLOAD_SPEED_E */
    BYTE    byRes[256];                     /*   Reserved */
}NETDEV_PLAYBACKINFO_S, *LPNETDEV_PLAYBACKINFO_S;

/**
 * @struct tagNETDEVPlayBackCondition
 * @brief   Parameters of play back by time Structure definition
 * @attention  None
 */
typedef struct tagNETDEVPlayBackCondition
{
    INT32   dwChannelID;                /*   Playback channel */
    INT64   tBeginTime;                 /*   Playback start time */
    INT64   tEndTime;                   /*   Playback end time */
    INT32   dwLinkMode;                 /*   Transport protocol, see enumeration #NETDEV_PROTOCAL_E */
    LPVOID  hPlayWnd;                   /*   Play window handle */
    INT32   dwFileType;                 /*   Recording storage type, see enumeration #NETDEV_PLAN_STORE_TYPE_E */
    INT32   dwDownloadSpeed;            /*  NETDEV_E_DOWNLOAD_SPEED_E */
    BYTE    byRes[256];                 /*   Reserved */
}NETDEV_PLAYBACKCOND_S, *LPNETDEV_PLAYBACKCOND_S;

/************************************************* *****************************************************/
/************************************************* PTZ services*****************************************************/
/**
 * @struct tagstNETDEVPtzPreset
 * @brief   PTZ preset information Structure definition
 * @attention  None
 */
typedef struct tagstNETDEVPtzPreset
{
    INT32   dwPresetID;                                 /*   Preset ID */
    CHAR    szPresetName[NETDEV_LEN_32];                /*   Preset name */
}NETDEV_PTZ_PRESET_S, *LPNETDEV_PTZ_PRESET_S;

/**
 * @struct tagstNETDEVPtzAllPresets
 * @brief   All PTZ presets Structure definition
 * @attention  None
 */
typedef struct tagstNETDEVPtzAllPresets
{
    INT32               dwSize;                             /*   Total number of presets */
    NETDEV_PTZ_PRESET_S astPreset[NETDEV_MAX_PRESET_NUM];   /*   Structure of preset information */
}NETDEV_PTZ_ALLPRESETS_S, *LPNETDEV_PTZ_ALLPRESETS_S;

/**
 * @struct tagNETDEVCruisePointInfo
 * @brief   PTZ preset patrol point information Structure definition
 * @attention  None
 */
typedef struct tagNETDEVCruisePoint
{
    INT32   dwPresetID;                     /*   Preset ID */
    INT32   dwStayTime;                     /*   Stay time */
    INT32   dwSpeed;                        /*   Speed */
    INT32   dwReserve;                      /*   Reserved */
}NETDEV_CRUISE_POINT_S, *LPNETDEV_CRUISE_POINT_S;

/**
 * @struct tagNETDEVCruiseInfo
 * @brief   PTZ preset patrol route information Structure definition 
 * @attention  None
 */
typedef struct tagNETDEVCruiseInfo
{
    INT32                   dwCuriseID;                                     /*   Route ID */
    CHAR                    szCuriseName[NETDEV_LEN_32];                    /*   Route name */
    INT32                   dwSize;                                         /*   Number of presets included in the route */
    NETDEV_CRUISE_POINT_S   astCruisePoint[NETDEV_MAX_CRUISEPOINT_NUM];     /*    Information of presets included in the route */
}NETDEV_CRUISE_INFO_S, *LPNETDEV_CRUISE_INFO_S;

/**
 * @struct tagNETDEVCruiseList
 * @brief   PTZ preset patrol route list Structure definition
 * @attention  None
 */
typedef struct tagNETDEVCruiseList
{
    INT32                   dwSize;                                         /*   Number of patrol routes */
    NETDEV_CRUISE_INFO_S    astCruiseInfo[NETDEV_MAX_CRUISEROUTE_NUM];      /*   Information of patrol routes */
}NETDEV_CRUISE_LIST_S, *LPNETDEV_CRUISE_LIST_S;

/**
 * @struct tagNETDEVPtzTrackinfo
 * @brief   Route information of PTZ route patrol Structure definition
 * @attention  None
 */
typedef struct tagNETDEVPtzTrackinfo
{
    INT32 dwTrackNum;                                               /*   Number of existing patrol routes */
    CHAR  aszTrackName[NETDEV_TRACK_CRUISE_MAXNUM][NETDEV_LEN_64];  /*   Route name */
}NETDEV_PTZ_TRACK_INFO_S, *LPNETDEV_PTZ_TRACK_INFO_S;

/**
 * @struct tagNETDEVPTZStatus
 * @brief   PTZ status Structure definition
 * @attention 010180-10180360  Absolute horizontal coordinates correspond to angles: 0 to 1 correspond to 0 to 180 degrees, and -1 to 0 correspond 180 to 360 degrees 
              01090  Absolute vertical coordinates correspond to angles: 0 to 1 correspond to 0 to 90 degrees 
              010  Absolute multiples correspond to the actual multiples: 0 to 1, correspond to 0 to maximum multiples 
 */
typedef struct tagNETDEVPTZStatus
{
    FLOAT                       fPanTiltX;              /*   Absolute horizontal coordinates*/
    FLOAT                       fPanTiltY;              /*   Absolute vertical coordinates*/
    FLOAT                       fZoomX;                 /*   Absolute multiples*/
    NETDEV_PTZ_MOVE_STATUS_E    enPanTiltStatus;        /*   PTZ Status*/
    NETDEV_PTZ_MOVE_STATUS_E    enZoomStatus;           /*   Focus Status*/
}NETDEV_PTZ_STATUS_S, *LPNETDEV_PTZ_STATUS_S;

/**
 * @struct tagNETDEVPTZAbsoluteMove
 * @brief    Absolute coodinates Structure definition
 * @attention  010180-10180360  Absolute horizontal coordinates correspond to angles: 0 to 1 correspond to 0 to 180 degrees, and -1 to 0 correspond 180 to 360 degrees 
               01090  Absolute vertical coordinates correspond to angles: 0 to 1 correspond to 0 to 90 degrees 
               010  Absolute multiples correspond to the actual multiples: 0 to 1, correspond to 0 to maximum multiples 
 */
typedef struct tagNETDEVPTZAbsoluteMove
{
    FLOAT                       fPanTiltX;                          /*  Absolute horizontal coordinates*/
    FLOAT                       fPanTiltY;                          /*  Absolute vertical coordinates*/
    FLOAT                       fZoomX;                             /*  Absolute multiples*/
}NETDEV_PTZ_ABSOLUTE_MOVE_S, *LPNETDEV_PTZ_ABSOLUTE_MOVE_S;

/**
 * @struct tagNETDEVRect
 * @brief   Rectangle Area  Structure definition
 * @attention  None
 */
typedef struct tagNETDEVRect
{
    INT32   dwLeft;                               /* x[0,10000]  X axis left point value [0,10000] */
    INT32   dwTop;                                /* y[0,10000]  Y axis top point value [0,10000] */
    INT32   dwRight;                              /* x[0,10000]  X axis right point value [0,10000] */
    INT32   dwBottom;                             /* y[0,10000]  Y axis bottom point value [0,10000] */
}NETDEV_RECT_S, *LPNETDEV_RECT_S;

/**
 * @struct tagNETDEVPtzOperateAreaInfo
 * @brief   Image area information Structure definition
 * @attention  None
 */
typedef struct tagNETDEVPtzOperateAreaInfo
{
    INT32   dwBeginPointX;                           /* X[0,10000]  Area start point X value [0,10000] */
    INT32   dwBeginPointY;                           /* Y[0,10000]  Area start point Y value [0,10000] */
    INT32   dwEndPointX;                             /* X[0,10000]  Area end point X value [0,10000] */
    INT32   dwEndPointY;                             /* Y[0,10000]  Area end point Y value [0,10000] */
}NETDEV_PTZ_OPERATEAREA_S, *LPNETDEV_PTZ_OPERATEAREA_S;

/**
 * @struct tagNETDEVPictureData
 * @brief   Image data Structure definition
 *         Storing pointer and length of decoded picture data
 * @attention  None
 */
typedef struct tagNETDEVPictureData
{
    BYTE    *pucData[4];                /* pucData[0]:Y ,pucData[1]:U ,pucData[2]:V   pucData[0]: Y plane pointer, pucData[1]: U plane pointer, pucData[2]: V plane pointer */
    INT32   dwLineSize[4];              /* ulLineSize[0]:Y, ulLineSize[1]:U, ulLineSize[2]:V  ulLineSize[0]: Y line spacing, ulLineSize[1]: U line spacing, ulLineSize[2]: V line spacing */
    INT32   dwPicHeight;                /*   Picture height */
    INT32   dwPicWidth;                 /*   Picture width */
    INT32   dwRenderTimeType;           /*   Time data type for rendering */
    INT64   tRenderTime;                /*   Time data for rendering */
}NETDEV_PICTURE_DATA_S, *LPNETDEV_PICTURE_DATA_S;

/**
 * @struct tagNETDEVWaveData
 * @brief   Audio data Structure definition
 *         Storing pointer and length of decoded picture data
 * @attention  None
 */
typedef struct tagNETDEVWaveData
{
    CHAR  *pcData;                      /*   Audio data pointer */
    INT32 dwDataLen;                    /*   Audio data length */
    INT32 dwWaveFormat;                 /*   Format of decoded audio*/
}NETDEV_WAVE_DATA_S, *LPNETDEV_WAVE_DATA_S;

/**
* @struct tagNETDEVParseAudioData
* @brief 
* @attention 
*/
typedef struct tagNETDEVParseAudioData
{
    BYTE *pucData;                  /*  Audio data pointer */
    UINT32 udwDataLen;              /*  Audio data length */
    UINT32 udwAudioCodeFormat;      /*  NETDEV_AUDIO_ENCODE_TYPE_E */
    UINT32 udwWaveFormat;           /*  NETDEV_WAVE_FORMAT_INFO_E */
    INT64 tTimeStamp;               /*  Time stamp (ms)*/
    BYTE  byRes[8];                 /*   Reserved */
}NETDEV_PARSE_AUDIO_DATA_S, *LPNETDEV_PARSE_AUDIO_DATA_S;

/**
 * @struct tagNETDEVParseVideoData
 * @brief   Video analytic data Structure definition
 *         Storing pointer and length of framed video data
 * @attention  None
 */
typedef struct tagNETDEVParseVideoData
{
    BYTE   *pucData;             /*   Pointer to video data */
    INT32  dwDataLen;            /*   Video data length */
    INT32  dwVideoFrameType;     /*  NETDEV_VIDEO_FRAME_TYPE_E  Frame type, see enumeration #NETDEV_VIDEO_FRAME_TYPE_E */
    INT32  dwVideoCodeFormat;    /*  NETDEV_PLAYER_VIDEO_CODE_TYPE_E  Video encoding format, see enumeration #NETDEV_PLAYER_VIDEO_CODE_TYPE_E */
    INT32  dwHeight;             /*   Video image height */
    INT32  dwWidth;              /*   Video image width */
    INT64  tTimeStamp;           /*  Time stamp (ms) */
    BYTE  byRes[8];              /*   Reserved */
}NETDEV_PARSE_VIDEO_DATA_S, *LPNETDEV_PARSE_VIDEO_DATA_S;


/**
 * @struct tagNETDEVVideoChlDetailInfo
 * @brief    Structure definition
 * @attention  None
 */
typedef struct tagNETDEVVideoChlDetailInfo
{
    INT32                       dwChannelID;            /*   Channel ID */
    BOOL                        bPtzSupported;          /*  Whether ptz is supported */
    NETDEV_CHANNEL_STATUS_E     enStatus;               /*   Channel status */
    INT32                       dwStreamNum;            /*   Number of streams */
    BYTE                        byRes[68];              /*   Reserved field*/
}NETDEV_VIDEO_CHL_DETAIL_INFO_S, *LPNETDEV_VIDEO_CHL_DETAIL_INFO_S;

/**
 * @struct tagNETDEVVideoStreamInfo
 * @brief   Channel video stream information Structure definition
 * @attention  None
 */
typedef struct tagNETDEVVideoStreamInfo
{
    NETDEV_LIVE_STREAM_INDEX_E  enStreamType;       /*   Stream index */
    INT32                       bEnableFlag;        /*   Enable or not */
    INT32                       dwHeight;           /*   Video encoding resolution - Height */
    INT32                       dwWidth;            /*   Video encoding resolution - Width */
    INT32                       dwFrameRate;        /*   Video encoding configuration frame rate */
    INT32                       dwBitRate;          /*   Bit rate */
    NETDEV_VIDEO_CODE_TYPE_E    enCodeType;         /*   Video encoding format */
    NETDEV_VIDEO_QUALITY_E      enQuality;          /*   Image quality */
    INT32                       dwGop;              /*   I-frame interval */
    BYTE                        byRes[32];          /*   Reserved */
}NETDEV_VIDEO_STREAM_INFO_S, *LPNETDEV_VIDEO_STREAM_INFO_S;


/**
* @enum tagNETDEVVideoResolution
* @brief  Video resolution
* @attention 
*/
typedef struct tagNETDEVVideoResolution
{
    INT32 dwWidth;
    INT32 dwHeight;
}NETDEV_VIDEO_RESOLUTION_S, *LPNETDEV_VIDEO_RESOLUTION_S;


/**
* @enum tagNETDEVRange
* @brief  Range
* @attention 
*/
typedef struct tagNETDEVRange
{
    INT32   dwMin;
    INT32   dwMax;
}NETDEV_RANGE_S, *LPNETDEV_RANGE_S;

/**
* @enum tagNETDEVVideoEncodeOption
* @brief  Video encode option
* @attention 
*/
typedef struct tagNETDEVVideoEncodeOption
{
    INT32                       dwEncodeType;                                       /*  NETDEV_VIDEO_CODE_TYPE_E*/
    INT32                       dwResolutionSize;                                   /*  Resolution size */
    NETDEV_VIDEO_RESOLUTION_S   astResolution[NETDEV_RESOLUTION_NUM_MAX];           /*  Resolution */
    NETDEV_RANGE_S              stIFrameInterval;                                   /*  I frame interval */
    NETDEV_RANGE_S              stFrameRate;                                        /*  Frame rate */
    NETDEV_RANGE_S              stEncodingInterval;                                 /*  Encode interval */
    NETDEV_RANGE_S              stBitRate;                                          /*  Bit rate */
}NETDEV_VIDEO_ENCODE_OPTION_S, *LPNETDEV_VIDEO_ENCODE_OPTION_S;

/**
* @enum tagNETDEVVideoStreamCap
* @brief  Video stream Cap
* @attention 
*/
typedef struct tagNETDEVVideoStreamCap
{
    INT32                           dwStreamType;                                   /*  NETDEV_LIVE_STREAM_INDEX_E */
    INT32                           dwEncodeCapSize;                                /*  Encode capability size */
    NETDEV_VIDEO_ENCODE_OPTION_S    astEncodeCap[NETDEV_VIDEO_ENCODE_TYPE_MAX];     /*  Encode capability */
    NETDEV_RANGE_S                  stQuality;                                      /*  Quality range */
}NETDEV_VIDEO_STREAM_CAP_S, *LPNETDEV_VIDEO_STREAM_CAP_S;

/**
 * @struct tagNETDEVLogFindCond
 * @brief   Log query condition Structure definition
 * @attention  None
 */
typedef struct tagNETDEVLogFindCond
{
    INT32      dwMainType;         /*  See #NETDEV_LOG_MAIN_TYPE_E for reference */
    INT32      dwSubType;          /*  See #NETDEV_LOG_SUB_TYPE_E for reference */
    INT64      tBeginTime;         /*  Start time */
    INT64      tEndTime;           /*  End time */
    INT32      dwLimitNum;         /*  Number of each query*/
    INT32      dwOffset;           /*  Start search from No. X. X starts from 0*/
}NETDEV_FIND_LOG_COND_S, *LPNETDEV_FIND_LOG_COND_S;

/**
* @struct tagNETDEVOptLogInfo
* @brief   Definition of log info structure
* @attention 
*/
typedef struct tagNETDEVOptLogInfo
{
    INT64       tTime;                                  /*  Log time*/
    INT32       dwMainType;                             /*  Main Type.See #NETDEV_LOG_MAIN_TYPE_E for reference*/
    INT32       dwSubType;                              /*  Sub Type.See #NETDEV_LOG_SUB_TYPE_E for reference*/
    INT32       dwChannelID;                            /*  Log source*/
    CHAR        szUserName[NETDEV_NAME_MAX_LEN];        /*  Username*/
    CHAR        szUserAddr[NETDEV_IPADDR_STR_MAX_LEN];  /*  User IP address*/
    BYTE        bRes[256];                              /*  Reserved */
}NETDEV_LOG_INFO_S,*LPNETDEV_LOG_INFO_S;

/*****************   Alarm services**************************************************/
/**
 * @struct tagNETDEVAlarmInfo
 * @brief   Alarm information Structure definition
 * @attention  None
 */
typedef struct tagNETDEVAlarmInfo
{
    INT32   dwAlarmType;                    /*  Alarm type, see enumeration #NETDEV_ALARM_TYPE_E */
    INT64   tAlarmTime;                     /*  Alarm time */
    INT32   dwChannelID;                    /*  Channel ID for NVR */
    UINT16  wIndex;                         /*  Index number,  disk slot index number */
    CHAR    *pszName;                       /*  Alarm source name, alarm input/output name */
    INT32   dwTotalBandWidth;               /*  Current total bandwidth (in MBps) */
    INT32   dwUnusedBandwidth;              /*  Bandwidth left (in MBps)*/
    INT32   dwTotalStreamNum;               /*  Total cameras*/
    INT32   dwFreeStreamNum;                /*  Cameras left */
    INT32   dwMediaMode;                    /*  Stream type. For enumerations, see#NETDEV_MEDIA_MODE_E*/
    BYTE    byRes[10];                      /*   Reserved */
}NETDEV_ALARM_INFO_S, *LPNETDEV_ALARM_INFO_S;

/**
 * @struct tagNETDEVPullAlarmInfo
 * @brief    Get alarm information Structure definition
 * @attention  None
 */
typedef struct tagNETDEVPullAlarmInfo
{
    NETDEV_ALARM_TYPE_E   enAlarm;         /*   Alarm type */
    INT32   dwChancelId;                   /*   Channel ID for NVR */
}NETDEV_PULLALARM_INFO_S, *LPNETDEV_PULLALARM_INFO_S;

/**********************  Passenger flow statistic **************************/
/**
 * @struct tagNETDEVPassengerFlowStatisticData
 * @brief    Passenger flow statistic infomation Sturcture definition
 * @attention  None
 */
typedef struct tagNETDEVPassengerFlowStatisticData
{
    INT32            dwChannelID;                  /*  Channel ID */
    INT64            tReportTime;                  /* unix Report time */
    INT32            tInterval;                    /*  Interval time */
    INT32            dwEnterNum;                   /*  Enter num */
    INT32            dwExitNum;                    /*  Exit num */
    INT32            dwTotalEnterNum;              /*  Total enter num */
    INT32            dwTotalExitNum;               /*  Total exit num */
}NETDEV_PASSENGER_FLOW_STATISTIC_DATA_S, *LPNETDEV_PASSENGER_FLOW_STATISTIC_DATA_S;


/************************************************ ******************************************************/

/**
 * @struct tagNETDEVSmartEncodeInfo 
 * @brief  Smart image encoding mode
 * @attention
 */
typedef struct tagNETDEVSmartEncodeInfo 
{
    UINT32 udwH264SmartEncodeModeNum;                                              /* H.264 Number of smart image encoding in H.264*/
    UINT32 audwH264SmartEncodeModeList[NETDEV_SMART_ENCODE_MODEL_MAX_NUM];         /* H.265NETDEV_SMART_ENCODE_MODE_E List of smart image encoding in H.265. See NETDEV_SMART_ENCODE_MODE_E for reference*/
    UINT32 udwH265SmartEncodeModeNum;                                              /* H.264 Number of smart image encoding in H.264*/
    UINT32 audwH265SmartEncodeModeList[NETDEV_SMART_ENCODE_MODEL_MAX_NUM];         /* H.265NETDEV_SMART_ENCODE_MODE_E List of smart image encoding in H.265. See NETDEV_SMART_ENCODE_MODE_E for reference */
}NETDEV_SMART_ENCODE_S,*LPNETDEV_SMART_ENCODE_S;


/**
 * @struct tagNETDEVResolutionCapability
 * @brief  Resolution details
 * @attention
 */
typedef struct tagNETDEVResolutionCapability
{
    UINT32 udwWidth;                                                                  /*  Image width*/
    UINT32 udwHeight;                                                                 /*  Image height*/
    UINT32 udwMinBitRate;                                                             /*  Minimum bit rate*/
    UINT32 udwMaxBitRate;                                                             /*  Maximum bit rate*/
    UINT32 udwDefaultBitRate;                                                         /*  Default bit rate*/
}NETDEV_RESOLUTION_CAPABILITY_S,*LPNETDEV_RESOLUTION_CAPABILITY_S;

/**
 * @struct tagNETDEVStreamCapability
 * @brief  Stream capability
 * @attention
 */
typedef struct tagNETDEVStreamCapability
{
    UINT32 udwstreamID;                                                             /*  Stream index. For enumeration, see NETDEV_LIVE_STREAM_INDEX_E */
    UINT32 udwResolutionNum;                                                        /*  Number of resolution*/
    UINT32 udwFrameRateNum;                                                         /*  Number of frame rate*/
    UINT32 udwMaxFrameRate;                                                         /*  Number of frame rate*/
    UINT32 udwMaxMJPEGFrameRate;                                                    /*  Maximum MJPEG frame rate of current stream*/
    UINT32 audwFrameRateList[NETDEV_LEN_16];                                        /*  Frame rate array*/
    NETDEV_RESOLUTION_CAPABILITY_S astResolutionCapabilityList[NETDEV_LEN_32];      /*   List of resolution*/
    NETDEV_SMART_ENCODE_S stSmartEncode;                                            /*  Smart image encoding mode*/
}NETDEV_STREAM_CAP_S,*LPNETDEV_STREAM_CAPABILITY_S;

/**
 * @struct tagNETDEVVideoModeInfo
 * @brief  Video mode capability
 * @attention
 */
typedef struct tagNETDEVVideoModeInfo 
{
    UINT32 udwWidth;                                      /*  Image width*/
    UINT32 udwHeight;                                     /*  Image height*/
    UINT32 udwFrameRate;                                  /*  Image frame rate*/
}NETDEV_VIDEO_MODE_INFO_S,*LPNETDEV_VIDEO_MODE_INFO_S;

/**
 * @struct tagNETDEVVideoCapabilityInfo
 * @brief  Encoding parameter capability
 * @attention
 */
typedef struct tagNETDEVVideoCapabilityInfo
{
    BOOL bIsSupportCfg;                                                             /* Support configuration or not. 0-No, 1-Yes*/
    BOOL bIsSupportSmoothLevel;                                                     /* Support smoothing or not. 0-No, 1-Yes*/
    BOOL bIsSupportImageFormat;                                                     /* Support configuration of image mode or not. 0-No, 1-Yes*/
    UINT32 udwEncodeFormatNum;                                                      /*  Number of video compression*/
    UINT32 audwEncodeFormatList[NETDEV_ENCODE_FORMAT_MAX_NUM];                      /*  Video compression list. See NETDEV_VIDEO_CODE_TYPE_E for reference */
    UINT32 udwMinIFrameInterval;                                                    /*  Minimum value of I Frame Interval*/
    UINT32 udwMaxIFrameInterval;                                                    /*  Maximum value of I Frame Interval*/
    UINT32 udwGOPTypeNum;                                                           /*  Number of GOP type*/
    UINT32 audwGOPTypeList[NETDEV_GOP_TYPE_MAX_NUM];                                /*  List of GOP type*/
    UINT32 udwVideoModeNum;                                                         /*  Number of video mode*/
    NETDEV_VIDEO_MODE_INFO_S astVideoModeList[NETDEV_LEN_16];                       /*  List of video mode capability*/
    UINT32 udwStreamCapNum;                                                         /*  Number of stream*/
    NETDEV_STREAM_CAP_S astStreamCapList[NETDEV_LEN_16];                            /*  List of stream capability*/
}NETDEV_VIDEO_STREAM_CAP_EX_S,*LPNETDEV_VIDEO_STREAM_CAP_EX_S;

/**
 * @struct tagNETDEVVideoCapabilityInfo
 * @brief  Video encoding parameter
 * @attention
 */
typedef struct tagNETDEVVideoEncodeInfo
{
    BOOL bEnableSVCMode;                        /*  SVC configuration. 0-Off, 1-On*/
    UINT32 udwEncodeFormat;                     /*  Video Compression. For enumeration, seeNETDEV_VIDEO_CODE_TYPE_E*/
    UINT32 udwWidth;                            /*  Image width*/
    UINT32 udwHeight;                           /*  Image height*/
    UINT32 udwBitrate;                          /*  Bit rate*/
    UINT32 udwBitrateType;                      /*  Bitrate type. See NETDEV_BIT_RATE_TYPE_E for reference */
    UINT32 udwFrameRate;                        /*  Frame rate*/
    UINT32 udwGopType;                          /*  GOP mode. See NETDEV_GOP_TYPE_E for reference */
    UINT32 udwIFrameInterval;                   /* I Frame Interval. The range depends on capability*/
    UINT32 udwImageQuality;                     /* Image quality, ranges from 1 to 9. 9 means the highest quality*/
    UINT32 udwSmoothLevel;                      /* Smoothing level, ranges from 1 to 9. 1 means the lowest level*/
    UINT32 udwSmartEncodeMode;                  /* NETDEV_SMART_ENCODE_MODE_E Smart encoding mode. See NETDEV_SMART_ENCODE_MODE_E for reference*/
}NETDEV_VIDEO_ENCODE_INFO_S,*LPNETDEV_VIDEO_ENCODE_INFO_S;

/**
 * @struct tagNETDEVVideoStreamInfoLapi
 * @brief (LAPI) Video stream info(LAPI)
 * @attention
 */
typedef struct tagNETDEVVideoStreamInfoLapi 
{
    BOOL bEnabled;                                                                  /*  Enable encoding for video stream or not*/
    UINT32 udwStreamID;                                                             /*  Stream index. For enumeration, seeNETDEV_LIVE_STREAM_INDEX_E*/
    UINT32 udwMainStreamType;                                                       /*  Main stream. See NETDEV_MAIN_STREAM_TYPE_E for reference */
    NETDEV_VIDEO_ENCODE_INFO_S stVideoEncodeInfo;                                   /*  Video encoding parameter*/
}NETDEV_VIDEO_STREAM_INFO_EX_S,*LPNETDEV_VIDEO_STREAM_INFO_EX_S;

/**
 * @struct tagNETDEVVideoStreamInfoList
 * @brief  Video stream list
 * @attention
 */
typedef struct tagNETDEVVideoStreamInfoList 
{
    UINT32 udwNum;                                                              /*  Number of video stream*/
    NETDEV_VIDEO_STREAM_INFO_EX_S astVideoStreamInfoList[NETDEV_LEN_16];        /*  Video stream list*/
}NETDEV_VIDEO_STREAM_INFO_LIST_S,*LPNETDEV_VIDEO_STREAM_INFO_LIST_S;



/***********************   Boolean configuration***************************** */

/**
 * @struct tagNETDEVAlarmInputInfo
 * @brief     Alarm boolean inputs info Structure definition
 * @attention  None
 */
typedef struct tagNETDEVAlarmInputInfo
{
    CHAR  szName[NETDEV_LEN_64];                /*    Name of input alarm */
}NETDEV_ALARM_INPUT_INFO_S, *LPNETDEV_ALARM_INPUT_INFO_S;

/**
 * @struct tagNETDEVAlarmInputInfoList
 * @brief     All Alarm boolean inputs info Structure definition
 * @attention  None
 */
typedef struct tagNETDEVAlarmInputInfoList
{
    INT32                        dwSize;                                           /*   Number of input alarms */
    NETDEV_ALARM_INPUT_INFO_S    astAlarmInputInfo[NETDEV_MAX_ALARM_IN_NUM];       /*   Configuration information of input alarms */
}NETDEV_ALARM_INPUT_LIST_S, *LPNETDEV_ALARM_INPUT_LIST_S;

/**
 * @struct tagNETDEVAlarmOutputInfo
 * @brief    Alarm boolean outputs info Structure definition
 * @attention  None
 */
typedef struct tagNETDEVAlarmOutputInfo
{   
    CHAR    szName[NETDEV_LEN_64];                  /*   Boolean name */
    INT32   dwChancelId;                            /*   Channel ID */
    INT32   enDefaultStatus;                        /*   Default status of boolean output, see enumeration #NETDEV_BOOLEAN_MODE_E */
    INT32   dwDurationSec;                          /*   S  Alarm duration (s) */
} NETDEV_ALARM_OUTPUT_INFO_S, *LPNETDEV_ALARM_OUTPUT_INFO_S;

/**
 * @struct tagNETDEVAlarmOutputList
 * @brief    All Alarm boolean outputs info Structure definition
 * @attention  None
 */
typedef struct tagNETDEVAlarmOutputList
{   
    INT32                       dwSize;                                                 /*    Number of booleans  */
    NETDEV_ALARM_OUTPUT_INFO_S  astAlarmOutputInfo[NETDEV_MAX_ALARM_OUT_NUM];           /*   Boolean configuration information */
} NETDEV_ALARM_OUTPUT_LIST_S, *LPNETDEV_ALARM_OUTPUT_LIST_S;

/**
 * @struct tagNETDEVTriggerAlarmOutput
 * @brief    Trigger boolean output alarm Structure definition
 * @attention  None
 */
typedef struct tagNETDEVTriggerAlarmOutput
{   
    CHAR                        szName[NETDEV_LEN_64];          /*   Boolean name */
    NETDEV_RELAYOUTPUT_STATE_E  enOutputState;                  /*  Trigger status, see enumeration #NETDEV_RELAYOUTPUT_STATE_E */
} NETDEV_TRIGGER_ALARM_OUTPUT_S, *LPNETDEV_TRIGGER_ALARM_OUTPUT_S;

/************************************************ OSD********************************************************/

/**
 * @struct tagNETDEVAreaScope
 * @brief   Area
 * @attention  None
 */
typedef struct tagNETDEVAreaScope
{
    INT32  dwLocateX;             /** x[0,10000] * Coordinates of top point x [0,10000] */
    INT32  dwLocateY;             /** y[0,10000] * Coordinates of top point y [0,10000] */
}NETDEV_AREA_SCOPE_S, *LPNETDEV_AREA_SCOPE_S;

/**
 * @struct tagNETDEVOsdTime
 * @brief OSD OSD time configuration information
 * @attention  None
 */
typedef struct tagNETDEVOsdTime
{
    BOOL                    bEnableFlag;        /* Enable time OSD, BOOL_TRUE means enable and BOOL_FALSE means disable */
    BOOL                    bWeekEnableFlag;    /* Display week or not (reserved) */
    NETDEV_AREA_SCOPE_S     stAreaScope;        /*  Area coordinates */
    UINT32                  udwTimeFormat;      /*  Time OSD format, see NETDEV_OSD_TIME_FORMAT_E */
    UINT32                  udwDateFormat;      /*  Date OSD format, see NETDEV_OSD_TIME_FORMAT_E */
}NETDEV_OSD_TIME_S, *LPNETDEV_OSD_TIME_S;

/**
 * @struct tagNETDEVOsdTextOverlay
 * @brief OSD OSD text overlay information
 * @attention
 */
typedef struct tagNETDEVOsdTextOverlay
{
    BOOL                    bEnableFlag;                /*  Enable OSD text overlay, BOOL_TRUE means enable and BOOL_FALSE means disable */
    NETDEV_AREA_SCOPE_S     stAreaScope;                /*  OSD text overlay area coordinates */
    CHAR                    szOSDText[NETDEV_OSD_TEXT_MAX_LEN];    /* OSD text overlay name strings */
    BYTE                    byRes[4];                               /*   Reserved */
}NETDEV_OSD_TEXT_OVERLAY_S, *LPNETDEV_OSD_TEXT_OVERLAY_S;

/**
 * @struct tagNETDEVOsdCfgInfo
 * @brief OSD Basic channel OSD information
 * @attention
 */
typedef struct tagNETDEVOsdCfgInfo
{
    NETDEV_OSD_TIME_S         stTimeOSD;        /*   Information of channel time OSD */
    NETDEV_OSD_TEXT_OVERLAY_S stNameOSD;        /*   Information of channel name OSD */
    INT16                     wTextNum;         /*   Text OSD number */
    NETDEV_OSD_TEXT_OVERLAY_S astTextOverlay[NETDEV_OSD_TEXTOVERLAY_NUM];   /* OSD  Information of channel OSD text overlay */
}NETDEV_VIDEO_OSD_CFG_S, *LPNETDEV_VIDEO_OSD_CFG_S;

/**
 * @struct tagAreaInfo
 * @brief  Definition of area configuration structure 
 * @attention
 */
typedef struct tagAreaInfo
{
    INT32   bIsEanbled;           /*   Enable or not. */
    INT32   dwTopLeftX;           /*   Upper left corner X [0, 10000]  */
    INT32   dwTopLeftY;           /*   Upper left corner Y [0, 10000]  */
    INT32   dwBottomRightX;       /*   Lower right corner x [0, 10000] */
    INT32   dwBottomRightY;       /*   Lower right corner y [0, 10000] */
    INT32   dwIndex;              /*   Index. */
}NETDEV_PRIVACY_MASK_AREA_INFO_S;

/**
 * @struct tagPrivacyMaskPara
 * @brief  Privacy mask configuration information
 * @attention
 */
typedef struct tagPrivacyMaskPara
{
    INT32                                  dwSize;                                     /*   Mask area number */ 
    NETDEV_PRIVACY_MASK_AREA_INFO_S        astArea[NETDEV_MAX_PRIVACY_MASK_AREA_NUM];  /*   Mask area parameters */
}NETDEV_PRIVACY_MASK_CFG_S, *LPNETDEV_PRIVACY_MASK_CFG_S;

/**
 * @struct tagNETDEVOsdCapabilities
 * @brief OSD OSD Capabilities
 * @attention
 */
typedef struct tagNETDEVOsdCapabilities
{
    BOOL     bIsSupportCfg;                                                     /*  Support configuration or not. 0-No, 1-Ye*/
    BOOL     bIsSupportFontSizeCfg;                                             /*  Support configuration of OSD size or not*/ 
    BOOL     bIsSupportFontColorCfg;                                            /*  upport configuration of OSD color or not*/ 
    UINT32   udwMaxAreaNum;                                                     /*  Maximum number of OSD area*/ 
    UINT32   udwMaxOSDNum;                                                      /*  Maximum number of OSD*/ 
    UINT32   udwMaxPerAreaOSDNum;                                               /*  Maximum number of OSD in each area*/ 
    UINT32   udwSupportedOSDTypeNum;                                            /*  Number of OSD content type*/ 
    UINT32   udwSupportedTimeFormatNum;                                         /*  Number of OSD time format*/ 
    UINT32   udwSupportedDateFormatNum;                                         /*  Number of OSD date format*/ 
    UINT32   aduwSupportedDateFormatList[NETDEV_OSD_DATE_FORMAT_MAX_NUM];       /* OSDNETDEV_OSD_DATE_FORMAT_E */ 
    UINT32   audwSupportedTimeFormatList[NETDEV_OSD_TIME_FORMAT_MAX_NUM];       /* OSDNETDEV_OSD_TIME_FORMAT_E */ 
    UINT32   audwSupportedOSDTypeList[NETDEV_OSD_TYPE_MAX_NUM];                 /* OSDNETDEV_OSD_CONTENT_TYPE_E */ 
}NETDEV_OSD_CAP_S, *LPNETDEV_OSD_CAP_S;

/**
 * @struct tagNETDEVOsdContentStyle
 * @brief OSD Display Style of channel OSD
 * @attention
 */
typedef struct tagNETDEVOsdContentStyle
{
    UINT32 udwFontStyle;                         /*   Font style. For enumeration, seeNETDEV_OSD_FONT_STYLE_E*/
    UINT32 udwFontSize;                          /*   Font Size. For enumeration, seeNETDEV_OSD_FONT_SIZE_E*/
    UINT32 udwColor;                             /*  Color*/
    UINT32 udwDateFormat;                        /*   Date Format. For enumeration, seeNETDEV_OSD_DATE_FORMAT_E */
    UINT32 udwTimeFormat;                        /*   Date Format. For enumeration, seeNETDEV_OSD_DATE_FORMAT_E */
    UINT32 audwFontAlignList[NETDEV_LEN_8];      /*   Font align in area, 8 areasfixed, IPcamera supported. For enumeration, seeNETDEV_OSD_ALIGN_E */
    UINT32 udwMargin;                            /*   Number of character with margin, IP camera supported. For enumeration, seeNETDEV_OSD_MIN_MARGIN_E */
}NETDEV_OSD_CONTENT_STYLE_S,*LPNETDEV_OSD_CONTENT_STYLE_S;

/**
 * @struct tagNETDEVContentInfo
 * @brief  Content
 * @attention
 */
typedef struct tagNETDEVContentInfo
{

    UINT32 udwContentType;                        /* OSD content type. For enumeration, see NETDEV_OSD_CONTENT_TYPE_E*/
    CHAR   szOSDText[NETDEV_OSD_TEXT_MAX_LEN];    /* OSD OSD text*/
}NETDEV_CONTENT_INFO_S,*LPNETDEV_CONTENT_INFO_S;

/**
 * @struct tagNETDEVOSDContentInfo
 * @brief OSD Channel OSD content
 * @attention
 */
typedef struct tagNETDEVOSDContentInfo
{
    BOOL   bEnabled;                                        /* OSD Enable OSD area*/
    UINT32 udwOSDID;                                        /* OSD[0,7] Area No., ranges from 0 to 7.*/
    UINT32 udwAreaOSDNum;                                   /* OSD Number of OSD in current area*/
    UINT32 udwTopLeftX;                                     /* OSD,[0,9999] X-axis of OSD area, ranges from 0 to 999*/
    UINT32 udwTopLeftY;                                     /* OSD,[0,9999] Y-axisof OSD area, ranges from 0 to 999*/
    NETDEV_CONTENT_INFO_S astContentInfo[NETDEV_LEN_8];     /* OSD OSD content in current area*/
}NETDEV_OSD_CONTENT_INFO_S,*LPNETDEV_OSD_CONTENT_INFO_S;

/**
 * @struct tagNETDEVOsdContent
 * @brief OSD All contents of channel OSD
 * @attention
 */
typedef struct tagNETDEVOsdContent
{
    UINT32                    udwNum;                          /* OSD Number of OSD area*/
    NETDEV_OSD_CONTENT_INFO_S astContentList[NETDEV_LEN_32];   /* OSD Content list of OSD area

*/
}NETDEV_OSD_CONTENT_S,*LPNETDEV_OSD_CONTENT_S;

/************************************************ ********************************************************/

/**
 * @struct tagNETDEVTamperAlarmInfo
 * @brief  Tampering detection analysis info
 * @attention  None
 */
typedef struct tagNETDEVTamperAlarmInfo
{
    INT32  dwSensitivity;                               /*   Sensitivity */
    BYTE   byRes[256];                                  /*   Reserved */
}NETDEV_TAMPER_ALARM_INFO_S, *LPNETDEV_TAMPER_ALARM_INFO_S;

/**
 * @struct tagNETDEVMotionAlarmInfo
 * @brief  Motion detection analysis info
 * @attention  None
 */
typedef struct tagNETDEVMotionAlarmInfo
{
    INT32  dwSensitivity;                                                     /*   Sensitivity */
    INT32  dwObjectSize;                                                      /*   Objection Size */
    INT32  dwHistory;                                                         /*   History */
    INT16  awScreenInfo[NETDEV_SCREEN_INFO_ROW][NETDEV_SCREEN_INFO_COLUMN];   /*   Screen Info */
    BYTE   byRes[64];                                                         /*   Reserved */
}NETDEV_MOTION_ALARM_INFO_S, *LPNETDEV_MOTION_ALARM_INFO_S;

/**
 * @struct tagNETDEVUpnpPortState
 * @brief   Protocol info
 * @attention  None
 */
typedef struct tagNETDEVUpnpPortState
{
    NETDEV_PROTOCOL_TYPE_E   eType;                            /*   Protocol type, see enumeration #NETDEV_PROTOCOL_TYPE_E */
    BOOL                     bEnbale;                          /*   Supported or not */
    INT32                    dwPort;                           /*   Port number */
    BYTE                     byRes[128];                       /*   Reserved */
}NETDEV_UPNP_PORT_STATE_S, *LPNETDEV_UPNP_PORT_STATE_S;


/**
 * @struct tagNETDEVUpnpNatState
 * @brief   Protocol info list
 * @attention  None
 */
typedef struct tagNETDEVUpnpNatState
{
    INT32   dwSize;                                            /*   Number of protocols */
    NETDEV_UPNP_PORT_STATE_S  astUpnpPort[NETDEV_LEN_16];      /*   Protocol info */
}NETDEV_UPNP_NAT_STATE_S, *LPNETDEV_UPNP_NAT_STATE_S;


/**
 * @struct tagNetDEVDiscoveryDevInfo
 * @brief   Info of discovered device
 * @attention  None
 */
typedef struct tagNetDEVDiscoveryDevInfo
{
    CHAR    szDevAddr[NETDEV_LEN_64];                            /*   Device address */
    CHAR    szDevModule[NETDEV_LEN_64];                          /*   Device model */
    CHAR    szDevSerailNum[NETDEV_LEN_64];                       /*   Device serial number */
    CHAR    szDevMac[NETDEV_LEN_64];                             /*   Device MAC address */
    CHAR    szDevName[NETDEV_LEN_64];                            /*   Device name */
    CHAR    szDevVersion[NETDEV_LEN_64];                         /*   Device version */
    NETDEV_DEVICETYPE_E  enDevType;                              /*   Device type */
    INT32   dwDevPort;                                           /*   Device port number */
    CHAR    szManuFacturer[NETDEV_LEN_64];                       /*  Device manufacture */
    BYTE    byRes[196];                                          /*   Reserved */
}NETDEV_DISCOVERY_DEVINFO_S, *LPNETDEV_DISCOVERY_DEVINFO_S;

/**
* @struct tagNETDEVTime
* @brief   Time parameter Structure definition
* @attention  None
*/
typedef struct tagNETDEVTime
{
    INT32   dwYear;                       /*   Year */
    INT32   dwMonth;                      /*   Month */
    INT32   dwDay;                        /*   Day */
    INT32   dwHour;                       /*   Hour */
    INT32   dwMinute;                     /*   Minute */
    INT32   dwSecond;                     /*   Second */
}NETDEV_TIME_S, *LPNETDEV_TIME_S;

/**
* @struct tagNETDEVSystemTimeInfo
* @brief   Time configuration structure definition
* @attention
*/
typedef struct tagNETDEVSystemTimeDST
{
    INT32 dwMonth;              /*   Month(1~12)*/
    INT32 dwWeekInMonth;        /*   1 for the first week and 5 for the last week in the month */
    INT32 dwDayInWeek;          /*    0 for Sunday and 6 for Saturday see enumeration NETDEV_DAY_IN_WEEK_E */
    INT32 dwHour;               /*   Hour */
}NETDEV_TIME_DST_S, *LPNETDEV_TIME_DST_S;

/**
* @struct tagNETDEVSystemTimeInfo
* @brief   Time configuration structure definition
* @attention
*/
typedef struct tagNETDEVSystemTimeDSTCfg
{
    NETDEV_TIME_DST_S   stBeginTime;        /* DST begin time see enumeration NETDEV_TIME_DST_S */
    NETDEV_TIME_DST_S   stEndTime;          /* DST end time see enumeration NETDEV_TIME_DST_S */
    INT32               dwOffsetTime;       /* DST saving time see enumeration NETDEV_DST_OFFSET_TIME */
}NETDEV_TIME_DST_CFG_S, *LPNETDEV_TIME_DST_CFG_S;

/**
* @struct tagNETDEVSystemTimeInfo
* @brief   Time configuration structure definition
* @attention
*/
typedef struct tagNETDEVSystemTimeInfo
{
    NETDEV_TIME_ZONE_E      dwTimeZone;             /*  Time zone, see enumeration #NETDEV_TIME_ZONE_E */
    NETDEV_TIME_S           stTime;                 /*  Time */
    BOOL                    bEnableDST;             /*  DST enable */
    NETDEV_TIME_DST_CFG_S   stTimeDSTCfg;           /*  DST time config*/
    BYTE                    byRes[220];             /*  Reserved */
}NETDEV_TIME_CFG_S, *LPNETDEV_TIME_CFG_S;

/**
* @struct tagNETDEVNetParam
* @brief    Timeout structure definition
* @attention
*/
typedef struct tagNETDEVRevTimeout
{
    INT32   dwRevTimeOut;                 /*  Set timeout for receiving */
    INT32   dwFileReportTimeOut;          /*  Set timeout for file operation */
    BYTE    byRes[128];                   /*   Reserved */
}NETDEV_REV_TIMEOUT_S, *LPNETDEV_REV_TIMEOUT_S;

/**
 * @struct tagNetDEVCloudDevLogin
 * @brief     Cloud Device information Structure definition
 * @attention , Obsoleted (not recommended)
 */
typedef struct tagNetDEVCloudDevLogin
{
    CHAR szDeviceName[NETDEV_LEN_64];       /*  Device name */
    CHAR szDevicePassword[NETDEV_LEN_64];   /*  Device login password (optional) */
    INT32 dwT2UTimeout;                     /*  15s P2P timeout (default: 15s) */
} NETDEV_CLOUD_DEV_LOGIN_S, *LPNETDEV_CLOUD_DEV_LOGIN_S;

/**
 * @struct tagNetDEVCloudDevLogin
 * @brief     Cloud Device information Structure definition
 * @attention  None
 */
typedef struct tagNetDEVCloudDevLoginEx
{
    CHAR szDeviceName[NETDEV_LEN_260];      /*  Device name */
    CHAR szDevicePassword[NETDEV_LEN_64];   /*  Device login password (optional) */
    INT32 dwT2UTimeout;                     /*  15s P2P timeout (default: 15s) */
} NETDEV_CLOUD_DEV_LOGIN_EX_S, *LPNETDEV_CLOUD_DEV_LOGIN_EX_S;

/**
 * @struct tagNETDEVCloudDevInfo
 * @brief   Cloud Device information Structure definition
 * @attention ,
 */
typedef struct tagNETDEVCloudDevInfo
{
    CHAR    szIPAddr[NETDEV_IPV4_LEN_MAX];              /*  Device IP */
    CHAR    szDevUserName[NETDEV_LEN_64];               /*  Device username */
    CHAR    szDevName[NETDEV_LEN_64];                   /*  Device name */
    CHAR    szDevModel[NETDEV_LEN_64];                  /*  Device model */
    CHAR    szDevSerialNum[NETDEV_LEN_64];              /*  Device serial number */
    INT32   dwOrgID;                                    /*  Home organization ID */
    INT32   dwDevPort;                                  /*  Device port */
}NETDEV_CLOUD_DEV_INFO_S,*LPNETDEV_CLOUD_DEV_INFO_S;


/**
 * @struct tagNETDEVCloudDevInfo
 * @brief   Cloud Device information Structure definition
 * @attention  None
 */
typedef struct tagNETDEVCloudDevInfoEx
{
    CHAR    szIPAddr[NETDEV_IPV4_LEN_MAX];              /*  Device IP */
    CHAR    szDevUserName[NETDEV_LEN_260];              /*  Device username */
    CHAR    szDevName[NETDEV_LEN_260];                  /*  Device name */
    CHAR    szDevModel[NETDEV_LEN_64];                  /*  Device model */
    CHAR    szDevSerialNum[NETDEV_LEN_64];              /*  Device serial number */
    INT32   dwOrgID;                                    /*  Home organization ID */
    INT32   dwDevPort;                                  /*  Device port */
    BYTE    byRes[128];                                 /*  */
}NETDEV_CLOUD_DEV_INFO_EX_S,*LPNETDEV_CLOUD_DEV_INFO_EX_S;

/**
 * @struct tagNETDEVDiskInfo
 * @brief  Disk info
 * @attention  None
 */
typedef struct tagNETDEVDiskInfo
{
    INT32 dwDiskCabinetIndex;
    INT32 dwSlotIndex;                          /*  Slot Index */
    INT32 dwTotalCapacity;                      /*  Total Capacity */
    INT32 dwUsedCapacity;                       /*  Used Capacity */
    NETDEV_DISK_WORK_STATUS_E enStatus;         /*  Status */
    CHAR szManufacturer[NETDEV_LEN_32];         /*  Manufacturer */
}NETDEV_DISK_INFO_S,*LPNETDEV_DISK_INFO_S;

/**
 * @struct tagNETDEVDiskInfoList
 * @brief  Disk info list
 * @attention  None
 */
typedef struct tagNETDEVDiskInfoList
{
    INT32 dwSize;                                       /*  Disk number */
    NETDEV_DISK_INFO_S astDisksInfo[NETDEV_DISK_MAX_NUM];     /*  Disk info */
}NETDEV_DISK_INFO_LIST_S,*LPNETDEV_DISK_INFO_LIST_S;

/**
* @struct tagNETDEVDefoggingInfo
* @brief  Defogging info
* @attention
*/
typedef struct tagNETDEVDefoggingInfo
{
    NETDEV_DEFOGGING_MODE_E  enDefoggingMode;           /*  Defogging mode */
    FLOAT                    fDefoggingLevel;           /*  Defogging level (0.0, 1.0) */
    BYTE                     bRes[64];                  /*  Reserved */
}NETDEV_DEFOGGING_INFO_S, *LPNETDEV_DEFOGGING_INFO_S;

/**
* @struct tagNETDEVFocusInfo
* @brief  Focus Info
* @attention
*/
typedef struct tagNETDEVFocusInfo
{
    NETDEV_FOCUS_MODE_E     enFocusMode;                /*  Defogging mode */
    BYTE                    bRes[16];                   /*  Reserved */
}NETDEV_FOCUS_INFO_S, *LPNETDEV_FOCUS_INFO_S;


/**
* @struct tagNETDEVIrFilterInfo
* @brief  IrCut filter info
* @attention
*/
typedef struct tagNETDEVIrFilterInfo
{
    NETDEV_IR_CUT_FILTER_MODE_E enIrCutFilterMode;      /*  IrCut Filter mode */
    BYTE                        bRes[16];               /*  Reserved */
}NETDEV_IRCUT_FILTER_INFO_S, *LPNETDEV_IRCUT_FILTER_INFO_S;

/**
* @struct tagNETDEVManualRecordcfg
* @brief   Manual Record structure definition
* @attention
*/
typedef struct tagNETDEVManualRecordcfg
{
    INT32                   dwChannelID;        /*   ChannelID */
    NETDEV_RECORD_TYPE_E    enRecordType;       /*  Record type #NETDEV_RECORD_TYPE_E */
    BYTE                    byRes[64];          /*   Reserved */
}NETDEV_MANUAL_RECORD_CFG_S, *LPNETDEV_MANUAL_RECORD_CFG_S;


/**
 * @struct tagNETDEVMonthInfo
 * @brief   get video by Month Structure definition
 * @attention  None
 */
typedef struct tagNETDEVMonthInfo
{
    UINT32  udwYear;        /*   year*/
    UINT32  udwMonth;       /*   month */
    UINT32  udwPosition;    /*  NETDEV_VIDEO_POSITION_E video query location */
}NETDEV_MONTH_INFO_S, *LPNETDEV_MONTH_INFO_S;

/**
 * @struct tagNETDEVMonthInfo
 * @brief   video status Structure definition
 * @attention  None
 */
typedef struct tagNETDEVMonthStatus
{
    UINT32  udwDayNumInMonth;                       /*  The number of a month's days */
    UINT32  szVideoStatus[NETDEV_MONTH_DAY_MAX];    /*  video status list, see in NETDEV_VIDEO_STATUS_E */
}NETDEV_MONTH_STATUS_S, *LPNETDEV_MONTH_STATUS_S;


/**
 * @struct tagNETDEVChannels
 * @brief   multichannel Structure definition
 * @attention  None
 */
typedef struct tagNETDEVChannels
{
    UINT32  udwSize;                            /*  Channel size */
    UCHAR   szChannelIDs[NETDEV_CHANNEL_MAX];   /*  Channel ID list[1,2,3,4] */
}NETDEV_CHANNELS_S, *LPNETDEV_CHANNELS_S;


/**
* @struct tagNETDEVTrafficStatisticsCond
* @brief   Command of Passenger flow statistic Structure definition
* @attention  None
*/
typedef struct tagNETDEVTrafficStatisticsCond
{
    INT32       dwChannelID;            /*  Channel ID */
    INT32       dwStatisticsType;       /*  NETDEV_TRAFFIC_STATISTICS_TYPE_E Statistics type */
    INT32       dwFormType;             /*  NETDEV_FORM_TYPE_E Form type */
    INT64       tBeginTime;             /*  Begin time */
    INT64       tEndTime;               /*  End time */
}NETDEV_TRAFFIC_STATISTICS_COND_S, *LPNETDEV_TRAFFIC_STATISTICS_COND_S;

/**
* @struct tagNETDEVTrafficStatisticsData
* @brief   Passenger flow statistic Structure definition
* @attention  None
*/
typedef struct tagNETDEVTrafficStatisticsData
{
    INT32  dwSize;                                          /*   */
    INT32  adwEnterCount[NETDEV_PEOPLE_CNT_MAX_NUM];        /*  */
    INT32  adwExitCount[NETDEV_PEOPLE_CNT_MAX_NUM];         /*  */
}NETDEV_TRAFFIC_STATISTICS_DATA_S, *LPNETDEV_TRAFFIC_STATISTICS_DATA_S;


/**
* @struct tagNETDEVGeolocationInfo
* @brief   Geolocation info Structure definition
* @attention  None
*/
typedef struct tagNETDEVGeolocationInfo 
{
    FLOAT fLongitude;       /*  Longitude */
    FLOAT fLatitude;        /*  Latitude */
}NETDEV_GEOLACATION_INFO_S, *LPNETDEV_GEOLACATION_INFO_S;

/**
* @struct tagNETDEVWiFiSnifferMacInfo
* @brief WIFISnifferMac   WIFISnifferMac info Structure definition 
* @attention  None
*/
typedef struct tagNETDEVWiFiSnifferMacInfo
{
    CHAR  aszMACInfo[NETDEV_WIFISNIFFER_MAC_MAX_NUM];     /* WiFi sniffer mac  WiFi sniffer mac address*/
    INT16 wMaxSig;                                        /* Mac,dBm Mac address corresponding max signal strength (in dBm) */
    CHAR  aszMaxSigTime[NETDEV_MAX_DATE_STRING_LEN];      /* Mac Time to obtain Mac address corresponding max signal strength*/
}NETDEV_WIFISNIFFER_MAC_INFO_S, *LPNETDEV_WIFISNIFFER_MAC_INFO_S;

/**
* @struct tagNETDEVWiFiSnifferMacList
* @brief WIFISnifferMac  WIFISnifferMac array Structure definition  
* @attention  None
*/
typedef struct tagNETDEVWiFiSnifferMacList
{
    INT32 dwSize;
    NETDEV_WIFISNIFFER_MAC_INFO_S  astMACList[NETDEV_WIFISNIFFER_MAC_ARRY_MAX_NUM];
}NETDEV_WIFISNIFFER_MAC_LIST_S, *LPNETDEV_WIFISNIFFER_MAC_LIST_S;

/* END********************************************************************************************************** */


/**
*   Type of pointer to media stream data callback function before being framed 
* @param [IN] lpPlayHandle       Current live playing handle
* @param [IN] pucBuffer          Pointer to buffer that stores stream data that is not framed
* @param [IN] dwBufSize          Buffer size
* @param [IN] dwMediaDataType   ,#NETDEV_MEDIA_DATA_FORMAT_E Media data type, see definitions of enumeration #NETDEV_MEDIA_DATA_TYPE_E
* @param [IN] lpUserParam       ,#NDPlayer_SetSourceMediaDataCB User-set parameters, specified by users when they call the #NDPlayer_SetSourceMediaDataCB function
* @return . None.
* @note  ,,. Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL *NETDEV_SOURCE_DATA_CALLBACK_PF)(IN LPVOID        lpPlayHandle,
                                                       IN const BYTE    *pucBuffer,
                                                       IN INT32         dwBufSize,
                                                       IN INT32         dwMediaDataType,
                                                       IN LPVOID        lpUserParam
                                                       );

/**
*   Type of pointer to callback function for framed stream data 
* @param [IN] lpPlayHandle           Current live playing handle
* @param [IN] pstParseVideoData      Pointer to buffer that stores framed video stream data
* @param [IN] lUserParam            ,#NDPlayer_SetParseVideoDataCB User-set parameters, specified by users when they call the #NDPlayer_SetParseVideoDataCB function
* @return . None.
* @note
* -     ,,. Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL *NETDEV_PARSE_VIDEO_DATA_CALLBACK_PF)(IN LPVOID lpPlayHandle,
                                                            IN const NETDEV_PARSE_VIDEO_DATA_S *pstParseVideoData,
                                                            IN LPVOID lpUserParam
                                                            );

/**
*   Type of pointer to callback function for decoded video stream data 
* @param [IN] lpPlayHandle       Current live playing handle
* @param [IN] pstPictureData     Pointer to buffer that stores decoded video stream data
* @param [IN] lpUserParam       ,#NDPlayer_SetDecodeVideoDataCB User-set parameters, specified by users when they call the #NDPlayer_SetDecodeVideoDataCB function
* @return . None.
* @note
* -     1.,,.
* -     1. Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
* -     2.yv12.Y0-Y1-......,U0-U1-......,V0-V1-......
* -     2. Video data is in yv12 format in sequence of Y0-Y1-......, U0-U1-......, V0-V1-......
*/
typedef void (STDCALL* NETDEV_DECODE_VIDEO_DATA_CALLBACK_PF)(IN LPVOID lpPlayHandle,
                                                             IN const NETDEV_PICTURE_DATA_S *pstPictureData,
                                                             IN LPVOID lpUserParam
                                                             );

/**
*   Type of pointer to callback function for framed stream data 
* @param [IN] lpPlayHandle    Current live playing handle
* @param [IN] pstWaveData     Pointer to buffer that stores decoded audio stream data
* @param [IN] lpUserParam    ,#NDPlayer_SetDecodeAudioDataCB User-set parameters, specified by users when they call the #NDPlayer_SetDecodeAudioDataCB function
* @return . None.
* @note
* -     ,,.
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_PARSE_AUDIO_DATA_CALLBACK_PF)(IN LPVOID lpPlayHandle,
                                                            IN const NETDEV_PARSE_AUDIO_DATA_S *pstParseAudioData,
                                                            IN LPVOID lpUserParam
                                                            );

/**
*   Type of pointer to callback function for decoded audio stream data 
* @param [IN] lpPlayHandle    Current live playing handle
* @param [IN] pstWaveData     Pointer to buffer that stores decoded audio stream data
* @param [IN] lpUserParam    ,#NDPlayer_SetDecodeAudioDataCB User-set parameters, specified by users when they call the #NDPlayer_SetDecodeAudioDataCB function
* @return . None.
* @note
* -     ,,.
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_DECODE_AUDIO_DATA_CALLBACK_PF)(IN LPVOID lpPlayHandle,
                                                             IN const NETDEV_WAVE_DATA_S *pstWaveData,
                                                             IN LPVOID lpUserParam
                                                             );

/**
*  Type of pointer to display data callback function
* @param [IN] lpHandle        Current live playing handle
* @param [IN] hdc            hdc,hdc  Display superficial hdc which can be used for drawing graphics.
* @param [IN] lpUserParam    ,#NETDEV_SetPlayDisplayCB User-set parameters, specified by users when they call the #NETDEV_SetPlayDisplayCB
* @return .
* @note
* -     ,,.
* -     Users should handle output stream data in a timely manner so that functions can be returned quickly. Otherwise, stream processing in the player will be affected.
*/
typedef void (STDCALL* NETDEV_DISPLAY_CALLBACK_PF)(IN LPVOID lpHandle,
                                                   IN LPVOID hdc,
                                                   IN LPVOID lpUserParam
                                                   );

/**
*   Callback function to receive alarm information
* @param [IN] lpUserID               User login ID
* @param [IN] dwChannelID            Channel ID
* @param [IN] NETDEV_ALARM_INFO_S    Alarm information
* @param [IN] lpBuf                  Pointer to buffer
* @param [IN] dwBufLen               Length of structure for alarm information
* @param [IN] dwBufLen               User data
* @note
*/
typedef void(STDCALL *NETDEV_AlarmMessCallBack_PF)(IN LPVOID    lpUserID,
                                                   IN INT32     dwChannelID,
                                                   IN NETDEV_ALARM_INFO_S   stAlarmInfo,
                                                   IN LPVOID    lpBuf,
                                                   IN INT32     dwBufLen,
                                                   IN LPVOID    lpUserData
                                                   );

/**
* .  Callback function to receive exception and reconnection messages
* @param [IN] lpUserID      User login ID
* @param [IN] dwType       :NETDEV_EXCEPTION_TYPE_E Type of exception or reconnection message: NETDEV_EXCEPTION_TYPE_E
* @param [IN] lpExpHandle   Exception type handle
* @param [IN] lpUserData    User data
* @note
*/
typedef void(STDCALL *NETDEV_ExceptionCallBack_PF)(IN LPVOID    lpUserID,
                                                   IN INT32     dwType,
                                                   IN LPVOID    lpExpHandle,
                                                   IN LPVOID    lpUserData
                                                   );
/**
 *   Callback function for passenger flow statistic message
 * @param [IN] lpUserID                 User login ID
 * @param [IN] pstPassengerFlowData     Passenger flow data
 * @param [IN] lpUserData                 User data
 * @note  None
 */
typedef void (STDCALL *NETDEV_PassengerFlowStatisticCallBack_PF)(IN LPVOID lpUserID,
                                                                 IN LPNETDEV_PASSENGER_FLOW_STATISTIC_DATA_S pstPassengerFlowData,
                                                                 IN LPVOID lpUserData
                                                                 );
/**
 *  Register callback function that used for count passenger flow
 * @param [IN] lpUserID                   User login ID
 * @param [IN] cbPassengerFlowStatisticCallBack      Callback function which will be registered
 * @param [IN] lpUserData                  User data
 */
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPassengerFlowStatisticCallBack(IN LPVOID lpUserID, 
                                                                              IN NETDEV_PassengerFlowStatisticCallBack_PF cbPassengerFlowStatisticCallBack, 
                                                                              IN LPVOID lpUserData
                                                                              );

/**
* ,ID, Register callback function and receive alarm information, etc. (Call back login ID at the same time to distinguish different devices)\n
* @param [IN] lpUserID               User login ID
* @param [IN] cbAlarmMessCallBack    Callback function
* @param [IN] lpUserData             User data
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetAlarmCallBack(IN LPVOID lpUserID,
                                                             IN NETDEV_AlarmMessCallBack_PF cbAlarmMessCallBack,
                                                             IN LPVOID lpUserData
                                                             );

/**
* sdk.  Callback function to register SDK, receive exception and reconnection messages, etc.
* @param [IN] cbExceptionCallBack       , Callback function to receive exception messages, used to call back information about current exceptions
* @param [IN] lpUserData                 User data
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetExceptionCallBack(IN NETDEV_ExceptionCallBack_PF cbExceptionCallBack,
                                                                 IN LPVOID lpUserData
                                                                 );

/**
*  Device discovery callback function
* @param [IN] pstDevInfo                 Device info
* @param [IN] lpUserData                 User data
* @note
*/
typedef void(STDCALL *NETDEV_DISCOVERY_CALLBACK_PF)(IN LPNETDEV_DISCOVERY_DEVINFO_S pstDevInfo,
                                                    IN LPVOID lpUserData
                                                    );

/**
*  Registered device discovery callback function
* @param [IN] cbDiscoveryCallBack    Callback function
* @param [IN] lpUserData             User data
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDiscoveryCallBack(IN NETDEV_DISCOVERY_CALLBACK_PF cbDiscoveryCallBack,
                                                                 IN LPVOID lpUserData
                                                                 );

/**
*  ,,
* This interface is used for device discovery. Please first register callback functions related to device discovery and use this interface for device discovery. Discovered device info will be included in the callback function.
* @param [IN]   pszBeginIP                 
* @param [IN]   pszEndIP                   
* @return TRUE,
* @note pszBeginIPpszEndIP"0.0.0.0",
*/
NETDEV_API NEWINTERFACE BOOL  STDCALL NETDEV_Discovery(IN CHAR *pszBeginIP,
                                                       IN CHAR *pszEndIP
                                                       );

/**
* SDK   SDK initialization
* @return TRUE, TRUE means success, and any other value means failure.
* @note  Thread not safe
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Init(void);

/**
* SDK   SDK cleaning
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Cleanup(void);

/**
* SDK Get SDK version information 
* @return SDK SDK version information
* @note
* - 2,2.0x000300003.0.
* - The two high bytes indicate the major version, and the two low bytes indicate the minor version. For example, 0x00030000 means version 3.0.
*/
NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetSDKVersion(void);



/**
*   User login
* @param [IN]  pszDevIP          Device IP
* @param [IN]  wDevPort          Device server port
* @param [IN]  pszUserName       Username
* @param [IN]  pszPassword       Password
* @param [OUT] pstDevInfo        Pointer to device information structure
* @return , 0 ,. Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_Login(IN char *pszDevIP,
                                                    IN INT16 wDevPort,
                                                    IN char *pszUserName,
                                                    IN char *pszPassword,
                                                    OUT LPNETDEV_DEVICE_INFO_S pstDevInfo
                                                    );

/**
*   User logout
* @param [IN] lpUserID     User login ID
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Logout(IN LPVOID lpUserID);

/**
*   Query channel info list
* @param [IN]    lpUserID            User login ID
* @param [INOUT] pdwChlCount         Number of channels
* @param [OUT]   pstVideoChlList     List of channel info list
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_QueryVideoChlDetailList(IN LPVOID   lpUserID,
                                                                    INOUT INT32 *pdwChlCount,
                                                                    OUT LPNETDEV_VIDEO_CHL_DETAIL_INFO_S pstVideoChlList
                                                                    );


/**
*   Query video channel info
* @param [IN]   lpUserID            User login ID
* @param [IN]   dwChannelID         Channel ID
* @param [OUT]  pstVideoChlInfo     video channel info
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_QueryVideoChlInfo(IN LPVOID lpUserID,
                                                              IN INT32 dwChannelID,
                                                              OUT LPNETDEV_VIDEO_CHL_DETAIL_INFO_S pstVideoChlInfo
                                                              );


/*************** Begin  Begin live view services*********************************************/

/**
*   Start live preview
* @param [IN]  lpUserID              User login ID
* @param [IN]  pstPreviewInfo        Preview parameter, see enumeration: NETDEV_PROTOCAL_E, NETDEV_LIVE_STREAM_INDEX_E.
* @param [IN]  cbRealDataCallBack    Pointer to callback function of stream data
* @param [IN]  lpUserData            User data
* @return , 0 ,. Returned user login ID. 0 indicates failure, and other values indicate the user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_RealPlay(IN LPVOID lpUserID,
                                                       IN LPNETDEV_PREVIEWINFO_S pstPreviewInfo,
                                                       IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                       IN LPVOID lpUserData
                                                       );

/**
*   Stop live preview
* @param [IN]  lpPlayHandle      Preview handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note NETDEV_RealPlay Stop the live view started by NETDEV_RealPlay
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopRealPlay(IN LPVOID lpPlayHandle);

/**
*   Local recording
* @param [IN]  lpPlayHandle          Preview handle
* @param [IN]  pszSaveFileName       Name of saved file
* @param [IN]  dwFormat             Format of saved file, see #NETDEV_MEDIA_FILE_FORMAT_E 
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SaveRealData(IN LPVOID  lpPlayHandle,
                                                         IN CHAR    *pszSaveFileName,
                                                         IN INT32   dwFormat
                                                         );

/**
*  Stop local recording
* @param [IN]  lpPlayHandle      Preview handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopSaveRealData(IN LPVOID lpPlayHandle);


/**
*   Get window bit rate
* @param [IN]  lpPlayHandle      Preview\playback handle
* @param [OUT] pdwBitRate        Pointer to obtained bit rate
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetBitRate(IN LPVOID lpPlayHandle,
                                                       OUT INT32 *pdwBitRate
                                                       );

/**
*   Get window frame rate
* @param [IN]  lpPlayHandle      Preview\playback handle
* @param [OUT] pdwFrameRate      Pointer to obtained frame rate
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetFrameRate(IN LPVOID lpPlayHandle,
                                                         OUT INT32 *pdwFrameRate
                                                         );

/**
*   Get window encoding format
* @param [IN]  lpPlayHandle          Preview\playback handle
* @param [OUT] pdwVideoEncFmt        Pointer to obtained encoding format, see NETDEV_VIDEO_CODE_TYPE_E
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetVideoEncodeFmt(IN LPVOID lpPlayHandle,
                                                              OUT INT32 *pdwVideoEncFmt
                                                              );


/**
*   Get video resolution
* @param [IN]  lpPlayHandle      Preview\playback handle
* @param [OUT] pdwWidth          Pointer to obtained resolution  width
* @param [OUT] pdwHeight         Pointer to obtained resolution  height
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetResolution(IN LPVOID lpPlayHandle,
                                                          OUT INT32 *pdwWidth,
                                                          OUT INT32 *pdwHeight
                                                          );

/**
*   Get window packet loss rate
* @param [IN]  lpPlayHandle      Preview\playback handle
* @param [OUT] pulRecvPktNum     Pointer to number of received packets
* @param [OUT] pulLostPktNum     Pointer to number of lost packets
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetLostPacketRate(IN LPVOID lpPlayHandle,
                                                              OUT INT32 *pulRecvPktNum,
                                                              OUT INT32 *pulLostPktNum
                                                              );

/**
*   Reset window packet loss rate
* @param [IN]  lpPlayHandle    Preview\playback handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ResetLostPacketRate(IN LPVOID lpPlayHandle);

/**
*   Live view snapshot
* @param [IN]  lpPlayHandle      Preview\playback handle
* @param [IN]  pszFileName       File path to save images (including file name)
* @param [IN]  dwCaptureMode     Image saving format, see #NETDEV_PICTURE_FORMAT_E
* @return TRUE, TRUE means success, and any other value means failure.
* @note  File format suffix is not required in the file name
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CapturePicture(IN LPVOID    lpPlayHandle,
                                                           IN char      *pszFileName,
                                                           IN INT32     dwCaptureMode
                                                           );

/**
*   Modify image display ratio
* @param [IN]  lpPlayHandle    Preview\playback handle
* @param [IN]  enRenderScale   Image display ratio
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetRenderScale(IN LPVOID lpPlayHandle,
                                                           IN NETDEV_RENDER_SCALE_E enRenderScale
                                                           );

/**
* ,  Get the current image info
* @param [IN]  lpPlayHandle    Preview\playback handle
* @param [IN]  pstImageInfo    Image information list
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetVideoEffect(IN LPVOID lpPlayHandle, 
                                                           OUT LPNETDEV_VIDEO_EFFECT_S pstImageInfo
                                                           );

/**
* ,  Adjust the current image
* @param [IN]  lpPlayHandle    Preview\playback handle
* @param [IN]  pstImageInfo    Image information list
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetVideoEffect(IN LPVOID lpPlayHandle, 
                                                           IN LPNETDEV_VIDEO_EFFECT_S pstImageInfo
                                                           );

/**
*   Set Digital zoom
* @param [IN] lpPlayHandle    Preview\playback handle
* @param [IN] hWnd             window handle 
* @param [IN] pstRect         Rectangle Area
* @return TRUE, TRUE means success, and any other value means failure.
* @note pstRect,, All images will be displayed with digital zoom disabled when pstRect is null
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDigitalZoom(IN LPVOID          lpPlayHandle, 
                                                           IN LPVOID          hWnd,
                                                           IN LPNETDEV_RECT_S pstRect
                                                           );

/**
*  Set pictuer fluency
* @param [IN] lpPlayHandle          Preview\playback handle
* @param [IN] dwFluency           NETDEV_PICTURE_FLUENCY_E
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPictureFluency(IN LPVOID lpPlayHandle,
                                                              IN INT32 dwFluency
                                                              );

/**
* :  Callback function to register streams (original stream)
* @param [IN]  lpPlayHandle                Live preview handle
* @param [IN]  cbSourceDataCallBack        Callback function for stream data
* @param [IN]  bContinue                   Whether to continue to following framing, decoding and displaying operations.
* @param [IN]  lpUser                      User data
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE  BOOL STDCALL NETDEV_SetPlayDataCallBack(IN LPVOID lpPlayHandle,
                                                                 IN NETDEV_SOURCE_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                                 IN INT32 bContinue,
                                                                 IN LPVOID lpUser);

/**
* :  Callback function to register live stream (framed stream data)
* @param [IN]  lpPlayHandle               Preview\playback handle
* @param [IN]  cbParsePlayDataCallBack    Data callback function
* @param [IN]  bContinue                  Whether to continue to following decoding and displaying operations.
* @param [IN]  lpUserData                 User data
* @return TRUE, TRUE means success, and any other value means failure.
* @note
* - ,NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayParseCB(IN LPVOID    lpPlayHandle,
                                                           IN NETDEV_PARSE_VIDEO_DATA_CALLBACK_PF cbParsePlayDataCallBack,
                                                           IN INT32     bContinue,
                                                           IN LPVOID    lpUserData
                                                           );

/**
*   Callback function to register live stream (decoded media stream data)
* @param [IN]  lpPlayHandle                  Preview\playback handle
* @param [IN]  cbPlayDecodeVideoCALLBACK     Data callback function
* @param [IN]  bContinue                     Whether to continue to following displaying operations.
* @param [IN]  lpUserData                    User data
* @return TRUE, TRUE means success, and any other value means failure.
* @note
* - ,NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayDecodeVideoCB(IN LPVOID  lpPlayHandle,
                                                                 IN NETDEV_DECODE_VIDEO_DATA_CALLBACK_PF cbPlayDecodeVideoCALLBACK,
                                                                 IN INT32   bContinue,
                                                                 IN LPVOID  lpUserData
                                                                 );

/**
*  Callback function to register audio stream (framed stream data)
* @param [IN]  lpPlayHandle                 Preview\playback handle
* @param [IN]  cbPlayParseAudioCallBack     Data callback function
* @param [IN]  lpUserData                   User data
* @return TRUE, TRUE means success, and any other value means failure.
* @note
* - ,NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayParseAudioCB(IN LPVOID lpPlayHandle,
                                                                IN NETDEV_PARSE_AUDIO_DATA_CALLBACK_PF cbPlayParseAudioCallBack,
                                                                IN INT32 bContinue,
                                                                IN LPVOID lpUserData
                                                                );

/**
*  Callback function to register audio stream (decoded media stream data)
* @param [IN]  lpPlayHandle                  Preview\playback handle
* @param [IN]  cbPlayDecodeAudioCallBack     Data callback function
* @param [IN]  lpUserData                    User data
* @return TRUE, TRUE means success, and any other value means failure.
* @note
* - ,NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayDecodeAudioCB(IN LPVOID lpPlayHandle,
                                                                 IN NETDEV_DECODE_AUDIO_DATA_CALLBACK_PF cbPlayDecodeAudioCallBack,
                                                                 IN INT32 bContinue,
                                                                 IN LPVOID lpUserData
                                                                 );

/**
*   Modify displayed data callback
* @param [IN]  lpPlayHandle              Preview\playback handle
* @param [IN]  cbPlayDisplayCallBack     Data callback function
* @param [IN]  lpUserData                User data
* @return TRUE, TRUE means success, and any other value means failure.
* @note
* - ,NULL.
* - To shut the callback function, set the second parameter as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetPlayDisplayCB(IN LPVOID lpPlayHandle,
                                                             IN NETDEV_DISPLAY_CALLBACK_PF cbPlayDisplayCallBack,
                                                             IN LPVOID lpUserData
                                                             );

/**
*  Start two-way audio
* @param [IN]  lpUserID                   User ID
* @param [IN]  dwChannelID                Channel ID
* @param [IN]  cbRealDataCallBack         Pointer to callback function of the stream data 
* @param [IN]  lpUserData                  User data
* @return , 0 , Returned user ID. 0 means failure, and any other value is a user ID.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_StartVoiceCom(IN LPVOID lpUserID,
                                                            IN INT32 dwChannelID,
                                                            IN NETDEV_DECODE_AUDIO_DATA_CALLBACK_PF cbPlayDataCallBack,
                                                            IN LPVOID lpUserData
                                                            );

/**
*  Stop two-way audio
* @param [IN]  lpPlayHandle    Two-way audio handle
* @return TRUE, TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopVoiceCom(IN LPVOID lpPlayHandle);

/**
*  Turn on microphone
* @param [IN]  lpPlayHandle    Preview handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_OpenMic(IN LPVOID lpPlayHandle);

/**
*  Turn off microphone
* @param [IN]  lpPlayHandle    Preview handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CloseMic(IN LPVOID lpPlayHandle);

/**
*   Adjust sound volume of microphone
* @param [IN]  lpPlayHandle      Preview handle 
* @param [IN]  dwVolume              Sound volume
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_MicVolumeControl(IN LPVOID lpPlayHandle,
                                                             IN INT32 dwVolume
                                                             );

/**
*  Get mic volume
* @param [IN]  lpPlayHandle      Preview handle
* @param [IN]  pdwVolume         Volume
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetMicVolume(IN LPVOID lpPlayHandle, 
                                                         OUT INT32* pdwVolume
                                                         );

/**
*  Get mute status
* @param [IN]  lpPlayHandle      Preview handle
* @param [OUT]  pbMute            Mute status
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetMuteStatus(IN LPVOID lpPlayHandle, 
                                                          OUT BOOL* pbMute
                                                          );

/**
*  Set mute status
* @param [IN]  lpPlayHandle      Preview handle
* @param [IN]  bMute             Mute status
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetMuteStatus(IN LPVOID lpPlayHandle, 
                                                          IN BOOL bMute
                                                          );


/**
*   Enable sound
* @param [IN]  lpPlayHandle    Preview handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_OpenSound(IN LPVOID lpPlayHandle);

/**
*  Control sound volume
* @param [IN]  lpPlayHandle    Preview handle
* @param [IN]  dwVolume        Volume
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SoundVolumeControl(IN LPVOID lpPlayHandle, 
                                                               IN INT32 dwVolume
                                                               );

/**
*  Get sound volume
* @param [IN]  lpPlayHandle      Preview handle
* @param [IN]  pdwVolume         Volume
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetSoundVolume(IN LPVOID lpPlayHandle, 
                                                           OUT INT32* pdwVolume
                                                           );

/**
*  Mute
* @param [IN]  lpPlayHandle    Preview handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CloseSound(IN LPVOID lpPlayHandle);

/*************** live view service*************************************************/

/*************** Begin playback service********************************************/

/**
* .  Query recording files according to file type and time
* @param [IN]  lpUserID      User login ID
* @param [IN]  pstFindCond     Search condition
* @return ,0,NETDEV_FindClose.
Recording search service number. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_FindClose.
* @note ,0,
*         .NETDEV_FindNextFilelpFindHandle,NETDEV_FindNextFile,.
*         .,NETDEV_FindCloselpFindHandle,NETDEV_FindClose,,.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindFile(IN LPVOID lpUserID,
                                                       IN LPNETDEV_FILECOND_S pstFindCond
                                                       );

/**
*   Obtain the information of found files one by one.
* @param [IN]  lpFindHandle      File search handle
* @param [OUT] pstFindData        Pointer to save file information
* @return TRUE, TRUE means success, and any other value means failure.
* @note  A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextFile(IN LPVOID lpFindHandle,
                                                         OUT LPNETDEV_FINDDATA_S pstFindData
                                                         );

/**
* ,  Close file search and release resources
* @param [IN] lpFindHandle   File search handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindClose(IN LPVOID lpFindHandle);


/**
*   Play back recording files by name
* @param [IN] lpUserID           User login ID
* @param [IN] pstPlayBackInfo   , LPNETDEV_PLAYBACKINFO_S Pointer to recording playback structure, see LPNETDEV_PLAYBACKINFO_S
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_PlayBackByName(IN LPVOID lpUserID,
                                                             IN LPNETDEV_PLAYBACKINFO_S pstPlayBackInfo
                                                             );

/**
*   Play back recording by time. 
* @param [IN] lpUserID           User login ID
* @param [IN] pstPlayBackCond      LPNETDEV_PLAYBACKCOND_S Pointer to playback-by-time structure, see LPNETDEV_PLAYBACKCOND_S
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_PlayBackByTime(IN LPVOID lpUserID,
                                                             IN LPNETDEV_PLAYBACKCOND_S pstPlayBackInfo
                                                             );

/**
*   Stop playback service
* @param [IN] lpPlayHandle   Playback handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopPlayBack(IN LPVOID lpPlayHandle);

/**
*  Download recordings by file name
* @param [IN]  lpUserID              User login ID
* @param [IN]  pstPlayBackInfo      , LPNETDEV_PLAYBACKINFO_S Pointer to recording playback structure, see LPNETDEV_PLAYBACKINFO_S
* @param [IN]  *pszSaveFileName     PC, Downloaded file save path on PC, must be an absolute path (including file name)
* @param [IN]  dwFormat              Recording file saving format
* @return , 0,NETDEV_StopGetFile. Download handle. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_StopGetFile.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_GetFileByName(IN LPVOID  lpUserID,
                                                            IN LPNETDEV_PLAYBACKINFO_S pstPlayBackInfo,
                                                            IN char    *pszSaveFileName,
                                                            IN INT32   dwFormat
                                                            );


/**
*  Download recordings by time
* @param [IN]  lpUserID                 User login ID
* @param [IN]  pstPlayBackCond   , LPNETDEV_PLAYBACKCOND_S Pointer to playback-by-time structure, see LPNETDEV_PLAYBACKCOND_S
* @param [IN]  *pszSaveFileName        PC, Downloaded file save path on PC, must be an absolute path (including file name)
* @param [IN]  dwFormat                 Recording file saving format
* @return , 0,NETDEV_StopGetFile. Download handle. 0 means failure. Other values are used as the handle parameters of functions like NETDEV_StopGetFile.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_GetFileByTime(IN LPVOID lpUserID, 
                                                            IN LPNETDEV_PLAYBACKCOND_S pstPlayBackCond, 
                                                            IN char *pszSaveFileName, 
                                                            IN INT32 dwFormat
                                                            );

/**
*  Stop downloading recording files
* @param [IN]  lpPlayHandle   Playback handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopGetFile(IN LPVOID lpPlayHandle);


/**
*   Control recording playback status.
* @param [IN]  lpPlayHandle      Playback or download handle
* @param [IN]  dwControlCode     Command for controlling recording playback status, see NETDEV_VOD_PLAY_CTRL_E
* @param [INOUT]  lpBuffer      Pointer to input/output parameters. For playing speed, see NETDEV_VOD_PLAY_STATUS_E. The type of playing time: INT64.
* @return TRUE, TRUE means success, and any other value means failure.
* @note ..,lpBufferNULL When playing, pause or resume videos, set IpBuffer as NULL.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PlayBackControl(IN LPVOID   lpPlayHandle,
                                                            IN INT32    dwControlCode,
                                                            INOUT LPVOID lpBuffer
                                                            );




/*********** End playback service ************************************************ */

/***********   Begin PTZ control ************************************************* */
/**
* ()  PTZ preset operation (preview required)
* @param [IN]  lpPlayHandle          Live preview handle
* @param [IN]  dwPTZPresetCmd        PTZ preset operation commands, see NETDEV_PTZ_PRESETCMD_E
* @param [IN]  pszPresetName         Preset name
* @param [IN]  dwPresetID            Preset number (starting from 1). Up to 255 presets are supported.
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZPreset(IN LPVOID lpPlayHandle,
                                                      IN INT32  dwPTZPresetCmd,
                                                      IN CHAR   *pszPresetName,
                                                      IN INT32  dwPresetID
                                                      );

/**
* ()  PTZ preset operation (preview not required)
* @param [IN]  lpUserID              User login ID
* @param [IN]  dwChannelID           Channel ID
* @param [IN]  dwPTZPresetCmd       PTZ preset operation commands, see NETDEV_PTZ_PRESETCMD_E
* @param [IN]  pszPresetName         Preset name
* @param [IN]  dwPresetID           1,255. Preset number (starting from 1). Up to 255 presets are supported.
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZPreset_Other(IN LPVOID   lpUserID,
                                                            IN INT32    dwChannelID,
                                                            IN INT32    dwPTZPresetCmd,
                                                            IN CHAR     *pszPresetName,
                                                            IN INT32    dwPresetID
                                                            );

/**
* ()  PTZ control operation (preview required)
* @param [IN]  lpPlayHandle          Live preview handle
* @param [IN]  dwPTZCommand          PTZ control commands, see #NETDEV_PTZ_E
* @param [IN]  dwSpeed               Speed of PTZ control, which is configured according to the speed control value of different decoders. Value ranges from 1 to 9.
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZControl(IN LPVOID    lpPlayHandle,
                                                       IN INT32     dwPTZCommand,
                                                       IN INT32     dwSpeed
                                                       );


/**
* ()  PTZ control operation (preview not required)
* @param [IN]  lpUserID              User login ID
* @param [IN]  dwChannelID           Channel ID
* @param [IN]  dwPTZCommand         NETDEV_PTZ_E
PTZ control commands, see #NETDEV_PTZ_E
* @param [IN]  dwSpeed              ,.[1,9] Speed of PTZ control, which is configured according to the speed control value of different decoders. Value ranges from 1 to 9.
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZControl_Other(IN LPVOID  lpUserID,
                                                             IN INT32   dwChannelID,
                                                             IN INT32   dwPTZCommand,
                                                             IN INT32   dwSpeed
                                                             );

/**
*   Get PTZ preset patrol route
* @param [IN]   lpUserID             User login ID
* @param [IN]   dwChannelID          Channel ID
* @param [OUT]  pstCruiseList         Patrol route list
* @return  TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetCruise(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         OUT LPNETDEV_CRUISE_LIST_S pstCruiseList
                                                         );

/**
* ()  PTZ preset patrol operation (preview not required)
* @param [IN]  lpUserID              User login ID
* @param [IN]  dwChannelID           Channel ID
* @param [IN]  dwPTZCruiseCmd        PTZ patrol operation commands, see #NETDEV_PTZ_CRUISECMD_E
* @param [IN]  pstCruiseInfo         PTZ patrol route information, see #LPNETDEV_CRUISE_INFO_S
* @return  TRUE, TRUE means success, and any other value means failure.
* @note
* - 1.,161 Patrol route. Up to 16 routes are supported (starting from 1).
* - 2.,321 Patrol point. Up to 32 points are supported (starting from 1).
* - 3.(255).(255).(40)  Preset (max 255), time (max 255) and speed (max 40).
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZCruise_Other(IN LPVOID lpUserID,
                                                            IN INT32 dwChannelID,
                                                            IN INT32 dwPTZCruiseCmd,
                                                            IN LPNETDEV_CRUISE_INFO_S pstCruiseInfo
                                                            );


/**
* ()  PTZ preset patrol operation (preview required)
* @param [IN]  lpPlayHandle          Live preview handle
* @param [IN]  dwPTZCruiseCmd        PTZ patrol operation commands, see NETDEV_PTZ_CRUISECMD_E
* @param [IN]  pstCruiseInfo         PTZ patrol route information, see #LPNETDEV_CRUISE_INFO_S
* @return  TRUE, TRUE means success, and any other value means failure.
* @note
* - 1.ID. Patrol route ID cannot be modified.
* - 2.,.  New routes are added one after another.
* - 3...,pstCruiseInfoID.  When deleting, starting or stopping patrol, enter patrol route ID in pstCruiseInfo.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZCruise(IN LPVOID lpPlayHandle,
                                                      IN INT32 dwPTZCruiseCmd,
                                                      IN LPNETDEV_CRUISE_INFO_S pstCruiseInfo
                                                      );


/**
*   Get PTZ patrol route
* @param [IN]   lpUserID             User login ID
* @param [IN]   dwChannelID          Channel ID
* @param [OUT]  pstTrackCruiseInfo   Patrol route list, see #LPNETDEV_PTZ_TRACK_INFO_S
* @return  TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZGetTrackCruise(IN LPVOID  lpUserID,
                                                              IN INT32   dwChannelID,
                                                              OUT LPNETDEV_PTZ_TRACK_INFO_S pstTrackCruiseInfo
                                                              );

/**
* ()   PTZ route patrol operation (preview not required)
* @param [IN]  lpUserID              User login ID
* @param [IN]  dwChannelID           Channel ID
* @param [IN]  dwPTZCruiseCmd        PTZ route patrol operation commands, see #NETDEV_PTZ_TRACKCMD_E
* @param [INOUT]  pszTrackCruiseName          Route patrol name, suggested length #NETDEV_LEN_64
* @return  TRUE, TRUE means success, and any other value means failure.
* @note
* - 1.,1  Only one patrol route allowed.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZTrackCruise(IN LPVOID lpUserID,
                                                           IN INT32 dwChannelID,
                                                           IN INT32 dwPTZTrackCruiseCmd,
                                                           INOUT CHAR *pszTrackCruiseName
                                                           );

/**
* .()   Drag to zoom in and out (preview required)
* @param [IN]  lpPlayHandle          Live preview handle
* @param [IN]  pstPtzOperateArea     Drag-to-zoom structure information
* @return TRUE, TRUE means success, and any other value means failure.
* @note NVR,IPC  In our NVR, this interface is supported only when our camera is connected through private protocol.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZSelZoomIn(IN LPVOID lpPlayHandle, 
                                                         IN LPNETDEV_PTZ_OPERATEAREA_S pstPtzOperateArea
                                                         );

/**
* .()   Drag to zoom in and out(preview not required)
* @param lpUserID                    User login ID
* @param [IN]  dwChannelID           Channel ID
* @param [IN]  pstPtzOperateArea     Drag-to-zoom structure information
* @return TRUE, TRUE means success, and any other value means failure.
* @note NVR,IPC  In our NVR, this interface is supported only when our camera is connected through private protocol.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZSelZoomIn_Other(IN LPVOID lpUserID,
                                                               IN INT32 dwChannelID,
                                                               IN LPNETDEV_PTZ_OPERATEAREA_S pstPtzOperateArea
                                                               );

/**
* ()  PTZ Home position (preview not required)
* @param [IN]  lpUserID                    User login ID
* @param [IN]  dwChannelID                 Channel ID
* @param [IN]  dwPTZHomePositionCmd       PTZ home position control commond NETDEV_PTZ_HOMEPOSITIONCMD_E
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZHomePosition_Other(IN LPVOID lpUserID, 
                                                                  IN INT32 dwChannelID, 
                                                                  IN INT32 dwPTZHomePositionCmd
                                                                  );

/**
* ()  PTZ Home position (preview required)
* @param [IN]  lpRealHandle              Live preview handle
* @param [IN]  dwPTZHomePositionCmd      PTZ home position control commond NETDEV_PTZ_HOMEPOSITIONCMD_E
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZHomePosition(IN LPVOID lpRealHandle, 
                                                            IN INT32 dwPTZHomePositionCmd
                                                            );
/**
*  PTZ absolute move
* @param [IN]  lpUserID                    User login ID
* @param [IN]  dwChannelID                 Channel ID
* @param [IN]  pstAbsoluteMove             PTZ absolute move info
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PTZAbsoluteMove(IN LPVOID lpUserID,
                                                            IN INT32 dwChannelID,
                                                            IN LPNETDEV_PTZ_ABSOLUTE_MOVE_S pstAbsoluteMove
                                                            );

/**********  End PTZ control ************************************************/

/**********  Begin remote parameter configuration ***********************/
/**
*  Obtain device capability
* @param [IN]   lpUserID                 User login ID
* @param [IN]  dwChannelID               Channel ID
* @param [IN]   dwCommand                NETDEV_CAPABILITY_COMMOND_E
* @param [OUT]  lpOutBuffer              Pointer to buffer that receives data
* @param [OUT]  dwOutBufferSize         Length (in byte) of buffer that receives data, cannot be 0.
* @param [OUT]  pdwBytesReturned         Pointer to length of received data, cannot be NULL.
* @return TRUE      TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDeviceCapability(IN LPVOID lpUserID,
                                                                IN INT32 dwChannelID,
                                                                IN INT32 dwCommand,
                                                                OUT LPVOID lpOutBuffer,
                                                                OUT INT32  dwOutBufferSize,
                                                                OUT INT32  *pdwBytesReturned
                                                                );

/**
*   Get configuration information of device
* @param [IN]   lpUserID                 User login ID
* @param [IN]   dwChannelID              Channel ID
* @param [IN]   dwCommand                Device configuration commands, see #NETDEV_CONFIG_COMMAND_E
* @param [OUT]  lpOutBuffer              Pointer to buffer that receives data
* @param [OUT]  dwOutBufferSize         Length (in byte) of buffer that receives data, cannot be 0.
* @param [OUT]  pdwBytesReturned          Pointer to length of received data, cannot be NULL.
* @return TRUE, TRUE means success, and any other value means failure.
* @note
* - 1.ID.  Route ID cannot be modified.
* - 2.,.  New routes are added one after another.
* - 3...,pstCruiseInfoID.  When deleting, starting or stoping a patrol route, enter route ID in pstCruiseInfo.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetDevConfig(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         IN INT32   dwCommand,
                                                         OUT LPVOID lpOutBuffer,
                                                         OUT INT32  dwOutBufferSize,
                                                         OUT INT32  *pdwBytesReturned
                                                         );

/**
*   Modify device configuration information
* @param [IN]   lpUserID             User login ID
* @param [IN]   dwChannelID          Channel ID
* @param [IN]   dwCommand            Device configuration commands, see #NETDEV_CONFIG_COMMAND_E
* @param [IN]   lpInBuffer           Pointer to buffer of input data
* @param [IN]   dwInBufferSize       Length of input data buffer (byte)
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetDevConfig(IN LPVOID  lpUserID,
                                                         IN INT32   dwChannelID,
                                                         IN INT32   dwCommand,
                                                         IN LPVOID  lpInBuffer,
                                                         IN INT32   dwInBufferSize
                                                         );



/**************  End remote parameter configuration ******************************/
/**
* \n
* Restart device\n
* @param [IN]  lpUserID      User login ID
* @return TRUE, TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_Reboot(IN LPVOID lpUserID);

/**
*   Restore to factory default settings
* @param [IN]  lpUserID      User login ID
* @return TRUE, TRUE means success, and any other value means failure.
* @note ,. Restore all parameters to factory settings, except network settings and user settings.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_RestoreConfig(IN LPVOID lpUserID);

/**
*   Get error codes
* @return  Error codes
*/
NETDEV_API NEWINTERFACE INT32 STDCALL NETDEV_GetLastError();

/**
*   Get alarm information from the device
* @param [IN]  lpUserID         User login ID
* @param [IN]  dwPullWaitTime   Alarm wait time (s)
* @param [INOUT] pdwListCnt     Maximum number of alarms. When working as an input parameter, it indicates the length of alarm information list; when working as an output parameter, it indicates the actual number of alarms.
* @param [OUT]   pstPullAlarmList   List of alarm information. The memory should be allocated in advance.
* @return TRUE, TRUE means success, and any other value means failure.
* note: login,logout,  Calling the function will block login and logout. It is not recommended to wait for a long time.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_PullAlarm(IN LPVOID lpUserID, 
                                                      IN INT32 dwPullWaitTime, 
                                                      INOUT INT32 *pdwListCnt, 
                                                      OUT LPNETDEV_PULLALARM_INFO_S pstPullAlarmList
                                                      );

/**
*   Snapshot without preview
* @param [IN]  lpUserID              User login ID
* @param [IN]  dwChannelID           Channel ID
* @param [IN]  dwStreamType;         Stream type, see enumeration #NETDEV_LIVE_STREAM_INDEX_E 
* @param [IN]  pszFileName           File path to save images (including file name)
* @param [IN]  dwCaptureMode         Image saving format, see #NETDEV_PICTURE_FORMAT_E
* @return  TRUE, TRUE means success, and any other value means failure.
* @note
        JPG.
        Only JPG format is supported.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_CaptureNoPreview(IN LPVOID lpUserID,
                                                             IN INT32 dwChannelID,
                                                             IN INT32 dwStreamType,
                                                             IN CHAR *pszFileName,
                                                             IN INT32 dwCaptureMode
                                                             );

/**
*  Dynamically create an I frame\n 
* @param [IN] lpUserID         User login ID
* @param [IN] dwChannelID      Channel ID
* @param [IN] dwStreamType     See enumeration NETDEV_LIVE_STREAM_INDEX_E
* @return NETDEV_E_SUCCEED     NETDEV_E_SUCCEED means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_MakeKeyFrame(IN LPVOID lpUserID,
                                                         IN INT32 dwChannelID,
                                                         IN INT32 dwStreamType
                                                         );

/**
*  Set keep-alive parameters
* @param [IN]  dwWaitTime              Waiting time
* @param [IN]  dwTrytimes              Connecting attempts
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetConnectTime(IN INT32 dwWaitTime,
                                                           IN INT32 dwTrytimes
                                                           );

/**
*  Set device name
* @param [IN] lpUserID          User login ID
* @param [IN] pszDeviceName      Device name
* @return TRUE,  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ModifyDeviceName(IN LPVOID lpUserID,
                                                             IN CHAR *pszDeviceName
                                                             );

/**
*  Get UPnP net state info
* @param [IN]   lpUserID      User login ID
* @param [IN]   pstNatState   UPnP nat state info
* @return TRUE,  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetUpnpNatState(IN LPVOID lpUserID,
                                                            OUT LPNETDEV_UPNP_NAT_STATE_S pstNatState
                                                            );

/**
*  Set UPnP net state info
* @param [IN]   lpUserID                   User login ID
* @param [IN]   pstNatState                UPnP nat state info
* @return TRUE,  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetUpnpNatState(IN LPVOID lpUserID,
                                                            IN LPNETDEV_UPNP_NAT_STATE_S pstNatState
                                                            );

/**
*  Set log path
* @param [IN]   pszLogPath    Log path (file name not included)
* @return TRUE,  TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetLogPath(IN CHAR *pszLogPath);

/**
*  Get device System time configuration
* @param [IN]  pstSystemTimeInfo      Pointer to time configuration structure
* @return TRUE,  TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetSystemTimeCfg(IN LPVOID lpUserID,
                                                             OUT LPNETDEV_TIME_CFG_S pstSystemTimeInfo
                                                             );

/**
*  Set device system time configuration
* @param [IN]  pstSystemTimeInfo      Pointer to time configuration structure
* @return TRUE,  TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetSystemTimeCfg(IN LPVOID lpUserID,
                                                             IN LPNETDEV_TIME_CFG_S pstSystemTimeInfo
                                                             );

/**
*  Set timeout
* @param [IN]  pstRevTimeout          Pointer to timeout
* @return TRUE,    TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_SetRevTimeOut( IN LPNETDEV_REV_TIMEOUT_S pstRevTimeout);


/**
*  User login to cloud account
* @param [IN]  pszCloudSrvUrl       URL  Cloud server URL 
* @param [IN]  pszUserName           Cloud account name
* @param [IN]  pszPassWord            Cloud account password 
* @return ID,-1,  Returned user ID. 1 means failure, any other value is a user ID.
* @note 
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_LoginCloud(IN CHAR *pszCloudSrvUrl,
                                                         IN CHAR *pszUserName,
                                                         IN CHAR *pszPassWord
                                                         );

/**
*  Cloud device login
* @param [IN]  lpUserID               Cloud account login ID 
* @param [IN]  pCloudInfo             Cloud device login info 
* @param [OUT] pstDevInfo              Pointer to device info structure
* @return ID,-1,  Returned user ID. 1 means failure, any other value is a user ID.
* @note 
    1.pCloudInfo szDevicePassword.The szDevicePassword field in pCloudInfo must be filled in.
    2.Deprecated, call NETDEV_LoginCloudDevEx().
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_LoginCloudDev(IN LPVOID lpUserID,
                                                            IN LPNETDEV_CLOUD_DEV_LOGIN_S pstCloudInfo, 
                                                            OUT LPNETDEV_DEVICE_INFO_S pstDevInfo
                                                            );

/**
*  Cloud device login
* @param [IN]  lpUserID               Cloud account login ID 
* @param [IN]  pCloudInfo             Cloud device login info 
* @param [OUT] pstDevInfo              Pointer to device info structure
* @return ID,-1,  Returned user ID. 1 means failure, any other value is a user ID.
* @note 
    1.pCloudInfo szDevicePassword.The szDevicePassword field in pCloudInfo must be filled in.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_LoginCloudDevEx(IN LPVOID lpUserID,
                                                              IN LPNETDEV_CLOUD_DEV_LOGIN_EX_S pstCloudInfo, 
                                                              OUT LPNETDEV_DEVICE_INFO_S pstDevInfo
                                                              );


/**
*    Cloud device login with dynamic password
* @param [IN]  lpUserID               Cloud account login ID
* @param [IN]  pCloudInfo             Cloud device login info
* @param [OUT] pstDevInfo              Pointer to device info structure
* @return ID,-1,  Returned user ID. 1 means failure, any other value is a user ID.
* @note 
    1.pCloudInfo szDevicePassword.The szDevicePassword field in pCloudInfo needs not to be filled in.
    2.Deprecated, call NETDEV_ LoginByDynamicEx().
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_LoginByDynamic(IN LPVOID lpUserID,
                                                             IN LPNETDEV_CLOUD_DEV_LOGIN_S pstCloudInfo,
                                                             OUT LPNETDEV_DEVICE_INFO_S pstDevInfo
                                                             );

/**
*    Cloud device login with dynamic password
* @param [IN]  lpUserID              Cloud account login ID
* @param [IN]  pCloudInfo             Cloud device login info
* @param [OUT] pstDevInfo              Pointer to device info structure
* @return ID,-1,  Returned user ID. 1 means failure, any other value is a user ID.
* @note 
    1.pCloudInfo szDevicePassword.The szDevicePassword field in pCloudInfo needs not to be filled in.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_LoginByDynamicEx(IN LPVOID lpUserID,
                                                               IN LPNETDEV_CLOUD_DEV_LOGIN_EX_S pstCloudInfo,
                                                               OUT LPNETDEV_DEVICE_INFO_S pstDevInfo
                                                               );



/**
*    Query device list under a cloud account
* @param [IN]  lpUserID             User login ID
* @return ,0,NETDEV_FindNextCloudDevInfo.NETDEV_FindCloseDevList.
Service ID. 0 means failure, any other value will be used as parameter of functions including NETDEV_FindNextCloudDevInfo and NETDEV_FindCloseDevList.
* @note ,0,
        The functions return value is the service number to search cloud device list. 0 means success:
*   1.NETDEV_FindNextCloudDevInfolpFindHandle,NETDEV_FindNextCloudDevInfo,.
    1.Use above service number as input parameter lpFindHandle for NETDEV_FindNextCloudDevInfo.
*   2.,NETDEV_FindCloseCloudDevListlpFindHandle,NETDEV_FindCloseCloudDevList,,.
    2.After searching, use above service number as input parameter lpFindHandle for NETDEV_FindCloseCloudDevList.Call NETDEV_FindCloseCloudDevList to release resource and close search.
*   3.Deprecated, call NETDEV_ FindCloudDevListEx().
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindCloudDevList(IN LPVOID lpUserID);


/**
*    Obtain info about detected devices one by one
* @param [IN]  lpFindHandle            Search handle
* @param [OUT] pstDevInfo              Pointer to saved device info
* @return TRUE, TRUE means success, and any other value means failure.
* @note 
    1. A returned failure indicates the end of search.
    2.Deprecated, call NETDEV_ FindNextCloudDevInfoEx().
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextCloudDevInfo(IN LPVOID lpFindHandle,
                                                                 OUT LPNETDEV_CLOUD_DEV_INFO_S pstDevInfo
                                                                 );

/**
* , Stop search and release resource 
* @param [IN] lpFindHandle   File search handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
    1.Deprecated, call NETDEV_ FindCloseCloudDevListEx().
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseCloudDevList(IN LPVOID lpFindHandle);

/**
*    Query device list under a cloud account
* @param [IN]  lpUserID             User login ID
* @return ,0,NETDEV_FindNextCloudDevInfo.NETDEV_FindCloseDevList.
Service ID. 0 means failure, any other value will be used as parameter of functions including NETDEV_FindNextCloudDevInfo and NETDEV_FindCloseDevList.
* @note ,0,
*         .NETDEV_FindNextCloudDevInfolpFindHandle,NETDEV_FindNextCloudDevInfo,.
*         .,NETDEV_FindCloseCloudDevListlpFindHandle,NETDEV_FindCloseCloudDevList,,.
*/

NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindCloudDevListEx(IN LPVOID lpUserID);

/**
*    Obtain info about detected devices one by one
* @param [IN]  lpFindHandle            Search handle
* @param [OUT] pstDevInfo              Pointer to saved device info
* @return TRUE, TRUE means success, and any other value means failure.
* @note  A returned failure indicates the end of search.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextCloudDevInfoEx(IN LPVOID lpFindHandle,
                                                                   OUT LPNETDEV_CLOUD_DEV_INFO_EX_S pstDevInfo
                                                                   );

/**
* , Stop search and release resource 
* @param [IN] lpFindHandle   File search handle
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseCloudDevListEx(IN LPVOID lpFindHandle);


/**
*  Obtain cloud device info by register code
* @param [IN]  lpUserID              User login ID
* @param [IN]  pszRegisterCode       Register code
* @param [IN]  pstDevInfo             Cloud device info
* @return TRUE,   TRUE means success, any other value indicates failure.
* @note 
    1.Deprecated, call NETDEV_ GetCloudDevInfoByRegCodeEx().
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCloudDevInfoByRegCode(IN LPVOID lpUserID,
                                                                     IN CHAR *pszRegisterCode,
                                                                     OUT LPNETDEV_CLOUD_DEV_INFO_S pstDevInfo
                                                                     );

/**
*  Obtain cloud device info by register code
* @param [IN]  lpUserID              User login ID
* @param [IN]  pszRegisterCode       Register code
* @param [IN]  pstDevInfo             Cloud device info
* @return TRUE,   TRUE means success, any other value indicates failure.
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCloudDevInfoByRegCodeEx(IN LPVOID lpUserID,
                                                                       IN CHAR *pszRegisterCode,
                                                                       OUT LPNETDEV_CLOUD_DEV_INFO_EX_S pstDevInfo
                                                                       );

/**
*   Obtain cloud device info by device name
* @param [IN]  lpUserID              User login ID
* @param [IN]  pszDevName            Device name
* @param [IN]  pstDevInfo             Cloud device info
* @return TRUE,   TRUE means success, any other value indicates failure.
* @note  
    1.Deprecated, call NETDEV_ GetCloudDevInfoByNameEx().
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCloudDevInfoByName(IN LPVOID lpUserID,
                                                                  IN CHAR *pszDevName,
                                                                  OUT LPNETDEV_CLOUD_DEV_INFO_S pstDevInfo
                                                                  );

/**
*   Obtain cloud device info by device name
* @param [IN]  lpUserID              User login ID
* @param [IN]  pszDevName            Device name
* @param [IN]  pstDevInfo             Cloud device info
* @return TRUE,   TRUE means success, any other value indicates failure.
* @note  
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCloudDevInfoByNameEx(IN LPVOID lpUserID,
                                                                    IN CHAR *pszDevName,
                                                                    OUT LPNETDEV_CLOUD_DEV_INFO_EX_S pstDevInfo
                                                                    );

/**
*  Start voice broadcast
* @param [IN]  lpUserID          User login ID
* @param [IN]  dwChannelID        Channel ID
* @return , 0 , Returned user ID. 0 means failure, and any other value is a user ID.
* @note , Voice broadcast and two-way audio for one channel are available.
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_StartVoiceBroadcast(IN LPVOID lpUserID, 
                                                                  IN INT32 dwChannelID
                                                                  );

/**
*  Stop voice broadcast
* @param [IN]  lpPlayHandle    voice broadcast handle
* @return TRUE, TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopVoiceBroadcast(IN LPVOID lpPlayHandle);

/**
*  Start manual record
* @param [IN]   lpUserID                 User login ID
* @param [IN]   pstManualRecordCfg       Manual record config
* @return TRUE, TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StartManualRecord(IN LPVOID lpUserID,
                                                              IN LPNETDEV_MANUAL_RECORD_CFG_S pstManualRecordCfg
                                                              );
/**
*  Stop manual record
* @param [IN]   lpUserID                 User login ID
* @param [IN]   pstManualRecordCfg       Manual record config
* @return TRUE, TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_StopManualRecord(IN LPVOID lpUserID,
                                                             IN LPNETDEV_MANUAL_RECORD_CFG_S pstManualRecordCfg
                                                             );


/**
*  Query video distribution information by month 
* @param [IN]   lpUserID             User login ID
* @param [IN]   dwChannelID           Channel ID
* @param [IN]   pstMonthInfo          Month information
* @param [OUT]   pstMonthStatus       Video status in the month
* @return TRUE, TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_QuickSearch(IN LPVOID lpUserID, 
                                                        IN INT32 dwChannelID , 
                                                        IN LPNETDEV_MONTH_INFO_S pstMonthInfo,
                                                        OUT LPNETDEV_MONTH_STATUS_S pstMonthStatus
                                                        );


/**
*  Obtain traffic statistic
* @param [IN]   lpUserID                 User login ID
* @param [OUT]  pstPeopleCounter         People counting list
* @return TRUE, TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetTrafficStatistic(IN LPVOID lpUserID,
                                                                IN LPNETDEV_TRAFFIC_STATISTICS_COND_S pstStatisticCond,
                                                                OUT LPNETDEV_TRAFFIC_STATISTICS_DATA_S pstTrafficStatistic
                                                                );

/**
*  Set log file size and number
* @param [IN] dwLogFileSize       The size of single log file
* @param [IN] dwLogFileNum        Log file number
* @return TRUE, TRUE means success, any other value indicates failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ConfigLogFile(IN INT32 dwLogFileSize,
                                                          IN INT32 dwLogFileNum
                                                          );

/**
*  Obtain geolocation info
* @param [IN]   lpUserID                 User login ID
* @param [IN]   dwChannelID              Channel ID
* @param [OUT]  pstGPSInfo               Geolocation info
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetGeolocationInfo(IN LPVOID lpUserID,
                                                               IN INT32 dwChannelID,
                                                               OUT LPNETDEV_GEOLACATION_INFO_S pstGPSInfo
                                                               );

/**
* wifi sniffer MAC Obtain wifi sniffer mac list
* @param [IN]   lpUserID                User login ID
* @param [IN]   dwChannelID             Channel ID
* @param [OUT]  pstMACList              Wifi sniffer Mac Wifi sniffer Mac address array
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetWifiSnifferMacList(IN LPVOID lpUserID,
                                                                  IN INT32 dwChannelID,
                                                                  OUT LPNETDEV_WIFISNIFFER_MAC_LIST_S pstMACList
                                                                  );

/**
*  Obtain compass info
* @param [IN]   lpUserID                User login ID
* @param [IN]   dwChannelID             Channel ID
* @param [OUT]  pfCompassInfo           Electronic compass info
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetCompassInfo(IN LPVOID lpUserID,
                                                           IN INT32 dwChannelID,
                                                           OUT FLOAT *pfCompassInfo
                                                           );

/**
* URL Obtain Live view stream url
* @param [IN]  lpUserID             User login ID
* @param [IN]  dwChannelID          Channel number
* @param [IN]  dwStreamType         Stream type see enumeration#NETDEV_LIVE_STREAM_INDEX_E
* @param [OUT] pszStreamUrl         URL Stream URL,NETDEV_LEN_260 The length must exceed NETDEV_LEN_260
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetStreamUrl(IN LPVOID  lpUserID, 
                                                         IN INT32   dwChannelID,
                                                         IN INT32   dwStreamType,
                                                         OUT CHAR   *pszStreamUrl
                                                         );

/**
* URL Obtain replay url
* @param [IN]  lpUserID              User login ID
* @param [IN]  dwChannelID           Channel number
* @param [IN]  dwStreamType          Stream type see enumeration#NETDEV_LIVE_STREAM_INDEX_E
* @param [OUT] pszReplayUrl  URL,NETDEV_LEN_260 The length must exceed NETDEV_LEN_260
* @return TRUE, TRUE means success, and any other value means failure.
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_GetReplayUrl(IN LPVOID  lpUserID, 
                                                         IN INT32   dwChannelID,
                                                         IN INT32   dwStreamType,
                                                         OUT CHAR   *pszReplayUrl
                                                         );

/**
* NVR Search NVR log by log type and time
* @param [IN]  lpUserID               ID User login ID
* @param [IN]  pstLogFindCond         Log search condition
* @return ,NETDEV_E_FAILEDNETDEV_CloseFindLog
Log search service number. NETDEV_E_FAILED means failure, and any other value is used as the parameter of functions like NETDEV_CloseFindLog.
* @note
*/
NETDEV_API NEWINTERFACE LPVOID STDCALL NETDEV_FindLogInfoList(IN LPVOID lpUserID,
                                                              IN LPNETDEV_FIND_LOG_COND_S pstLogFindCond
                                                              );

/**
*  Obtain logone by one
* @param [IN]  lFindHandle            Log search handle
* @param [OUT] pstFindData            Pointer to saved log info
* @return NETDEV_E_SUCCEED NETDEV_E_SUCCEED means success, and any other value means failure
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindNextLogInfo(IN LPVOID lpFindHandle,
                                                            OUT LPNETDEV_LOG_INFO_S pstLogInfo
                                                            );

/**
*  Close log search and release resource
* @param [IN]  lFindHandle            File search handle
* @return NETDEV_E_SUCCEED NETDEV_E_SUCCEED means success, and any other value means failure
* @note
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_FindCloseLogInfo(IN LPVOID lpFindHandle);


/**
*  eset people counting
* @param [IN]   lpUserID              User login ID
* @param [IN]   dwChannelID           Channel ID
* @return TRUE TRUE means success, and any other value means failure.
*/
NETDEV_API NEWINTERFACE BOOL STDCALL NETDEV_ResetPassengerFlow(IN LPVOID lpUserID,
                                                               IN INT32 dwChannelID
                                                               );


#ifdef  __cplusplus
}
#endif  /* end of __cplusplus */

#endif  /* end of _NETDEV_NET_SDK_H_ */

