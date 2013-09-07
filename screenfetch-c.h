/*  screenfetch-c.h
	Author: William Woodruff
	-------------
	
	The functions, macros, and ascii logos used in screenfetch-c.c are defined/prototyped here.
	Like screenfetch-c.c, this file is licensed under the MIT license.
	You should have received a copy of it with this code.
*/

/* a number is assigned to each OS or OS family */
#define UNKNOWN 0
#define CYGWIN 1
#define OSX 2
#define LINUX 3
#define FREEBSD 4
#define NETBSD 5
#define OPENBSD 6
#define DFBSD 7

/* quick macro for when all BSDs have the same function syntax */
#define ISBSD() ((OS >= 4 && OS <= 7) ? true : false)

#ifdef __CYGWIN__
	#define OS CYGWIN
	FILE* popen(const char* command, const char* type);
	int pclose(FILE* stream);
#elif defined __APPLE__ && __MACH__
	#define OS OSX
#elif defined __linux__
	#define OS LINUX
	#include <sys/sysinfo.h> /* the sysinfo struct contains all kinds of useful info (uptime, ram stats, etc) */
#elif defined __FreeBSD__
	#define OS FREEBSD
#elif defined __NetBSD__
	#define OS NETBSD
#elif defined __OpenBSD__
	#define OS OPENBSD
#elif defined __DragonFly__
	#define OS DFBSD
#else 
	#define OS UNKNOWN
#endif


/* color/fmt definitions */
#define TNRM "\x1B[0m" /* normal */
#define TBLD "\x1B[1m" /* bold */
#define TULN "\x1B[4m" /* underlined */
#define TBLK "\x1B[30m" /* black */
#define TRED "\x1B[31m" /* red */
#define TGRN "\x1B[32m" /* green */
#define TBRN "\x1B[33m" /* brown */
#define TBLU "\x1B[34m" /* blue */
#define TPUR "\x1B[35m" /* purple */
#define TCYN "\x1B[36m" /* cyan */
#define TLGY "\x1B[37m" /* light gray */
#define TDGY "\x1B[1;30m" /* dark gray */
#define TLRD "\x1B[1;31m" /* light red */
#define TLGN "\x1B[1;32m" /* light green */
#define TYLW "\x1B[1;33m" /* yellow */
#define TLBL "\x1B[1;34m" /* light blue */
#define TLPR "\x1B[1;35m" /* light purple */
#define TLCY "\x1B[1;36m" /* light cyan */
#define TWHT "\x1B[1;37m" /* white */

/* other definitions, use with caution (not type safe) */
#define MAX_STRLEN 128
#define SET_VERBOSE(flag) (verbose = flag)
#define SET_DEBUG(flag) (debug = flag)
#define SET_ERROR(flag) (error = flag)
#define SET_SCREENSHOT(flag) (screenshot = flag)
#define SET_DISTRO(str) (safe_strncpy(distro_str, str, MAX_STRLEN))
#define STRCMP(x, y) (!strcmp(x, y))
#define DEBUG_OUT(str1, str2) (fprintf(stderr, TYLW "[[ DEBUG ]] " "%s%s\n" TNRM, str1, str2))
#define ERROR_OUT(str1, str2) (fprintf(stderr, TWHT "[[ " TLRD "!" TWHT " ]] " TNRM "%s%s\n", str1, str2))
#define VERBOSE_OUT(str1, str2) (fprintf(stdout, TLRD ":: " TNRM "%s%s\n", str1, str2))


/* screenfetch detection function definitions */
void detect_distro(char* str);
void detect_arch(char* str);
void detect_host(char* str);
void detect_kernel(char* str);
void detect_uptime(char* str);
void detect_pkgs(char* str);
void detect_cpu(char* str);
void detect_gpu(char* str);
void detect_disk(char* str);
void detect_mem(char* str);
void detect_shell(char* str);
void detect_res(char* str);
void detect_de(char* str);
void detect_wm(char* str);
void detect_wm_theme(char* str);
void detect_gtk(char* str);
void fill_detected_arr(char* arr[], char* distro, char* arch, char* host, char* kernel, char* uptime, char* pkgs, char* cpu, char* gpu, char* disk, char* mem, char* shell, char* res, char* de, char* wm, char* wm_theme, char* gtk);

/* other function definitions */
void main_output(char* data[], char* data_names[]);
char* safe_strncpy(char* destination, const char* source, size_t num); 
void split_uptime(float uptime, int* secs, int* mins, int* hrs, int* days);
void display_version(void);
void display_help(void);
void take_screenshot(void);


/* tested, working */
char* oldarch_logo[] = 
{
	""TWHT"              __                     " TNRM,
	""TWHT"          _=(SDGJT=_                 " TNRM,
	""TWHT"        _GTDJHGGFCVS)                " TNRM,
	""TWHT"       ,GTDJGGDTDFBGX0               " TNRM,
	""TWHT"      JDJDIJHRORVFSBSVL"TLBL"-=+=,_        " TNRM,
	""TWHT"     IJFDUFHJNXIXCDXDSV,"TLBL"  \"DEBL      " TNRM,
	""TWHT"    [LKDSDJTDU=OUSCSBFLD."TLBL"   '?ZWX,   " TNRM,
	""TWHT"   ,LMDSDSWH'     `DCBOSI"TLBL"     DRDS]," TNRM,
	""TWHT"   SDDFDFH'         !YEWD,"TLBL"   )HDROD  " TNRM,
	""TWHT"  !KMDOCG            &GSU|"TLBL"_GFHRGO' " TNRM,
	""TWHT"  HKLSGP'"TLBL"           __"TWHT"TKM0"TLBL"GHRBV)'  " TNRM,
	""TWHT" JSNRVW'"TLBL"       __+MNAEC"TWHT"IOI,"TLBL"BN'     " TNRM,
	""TWHT" HELK['"TLBL"    __,=OFFXCBGHC"TWHT"FD)         " TNRM,
	""TWHT" ?KGHE "TLBL"_-#DASDFLSV='"TWHT"    'EF         " TNRM,
	""TWHT" 'EHTI                    !H         " TNRM,
	""TWHT"  `0F'                    '!        " TNRM,
	"                                     " TNRM,
	"                                     " TNRM
};

/* tested, working */
char* arch_logo[] =
{
	""TLCY"                   -`",
	""TLCY"                  .o+`                 " TNRM,
	""TLCY"                 `ooo/                " TNRM,
	""TLCY"                `+oooo:               " TNRM,
	""TLCY"               `+oooooo:              " TNRM,
	""TLCY"               -+oooooo+:             " TNRM,
	""TLCY"             `/:-:++oooo+:            " TNRM,
	""TLCY"            `/++++/+++++++:           " TNRM,
	""TLCY"           `/++++++++++++++:          " TNRM,
	""TLCY"          `/+++o"TCYN"oooooooo"TLCY"oooo/`        " TNRM,
	""TCYN"         "TLCY"./"TCYN"ooosssso++osssssso"TLCY"+`       " TNRM,
	""TCYN"        .oossssso-````/ossssss+`      " TNRM,
	""TCYN"       -osssssso.      :ssssssso.     " TNRM,
	""TCYN"      :osssssss/        osssso+++.    " TNRM,
	""TCYN"     /ossssssss/        +ssssooo/-    " TNRM,
	""TCYN"   `/ossssso+/:-        -:/+osssso+-  " TNRM,
	""TCYN"  `+sso+:-`                 `.-/+oso: " TNRM,
	""TCYN" `++:.                           `-/+/" TNRM,
	""TCYN" .`                                 `/" TNRM
};

/* tested, working */
char* mint_logo[] =
{
	"                                       " TNRM,
	""TLGN" MMMMMMMMMMMMMMMMMMMMMMMMMmds+.       " TNRM,
	""TLGN" MMm----::-://////////////oymNMd+`    " TNRM,
	""TLGN" MMd      "TWHT"/++                "TLGN"-sNMd:   " TNRM,
	""TLGN" MMNso/`  "TWHT"dMM    `.::-. .-::.` "TLGN".hMN:  " TNRM,
	""TLGN" ddddMMh  "TWHT"dMM   :hNMNMNhNMNMNh: "TLGN"`NMm  " TNRM,
	""TLGN"     NMm  "TWHT"dMM  .NMN/-+MMM+-/NMN` "TLGN"dMM  " TNRM,
	""TLGN"     NMm  "TWHT"dMM  -MMm  `MMM   dMM. "TLGN"dMM  " TNRM,
	""TLGN"     NMm  "TWHT"dMM  -MMm  `MMM   dMM. "TLGN"dMM  " TNRM,
	""TLGN"     NMm  "TWHT"dMM  .mmd  `mmm   yMM. "TLGN"dMM  " TNRM,
	""TLGN"     NMm  "TWHT"dMM`  ..`   ...   ydm. "TLGN"dMM  " TNRM,
	""TLGN"     hMM- "TWHT"+MMd/-------...-:sdds  "TLGN"dMM  " TNRM,
	""TLGN"     -NMm- "TWHT":hNMNNNmdddddddddy/`  "TLGN"dMM  " TNRM,
	""TLGN"      -dMNs-"TWHT"``-::::-------.``    "TLGN"dMM  " TNRM,
	""TLGN"       `/dMNmy+/:-------------:/yMMM  " TNRM,
	""TLGN"          ./ydNMMMMMMMMMMMMMMMMMMMMM  " TNRM,
	""TLGN"             .MMMMMMMMMMMMMMMMMMM    " TNRM,
	"                                      " TNRM
};

/* tested, working */
char* lmde_logo[] =
{
	"          "TWHT"`.-::---..            " TNRM,
	""TLGN"       .:++++ooooosssoo:.      " TNRM,
	""TLGN"     .+o++::.      `.:oos+.    " TNRM,
	""TLGN"    :oo:.`             -+oo"TWHT":   " TNRM,
	""TLGN"  "TWHT"`"TLGN"+o/`    ."TWHT"::::::"TLGN"-.    .++-"TWHT"`  " TNRM,
	""TLGN" "TWHT"`"TLGN"/s/    .yyyyyyyyyyo:   +o-"TWHT"`  " TNRM,
	""TLGN" "TWHT"`"TLGN"so     .ss       ohyo` :s-"TWHT":  " TNRM,
	""TLGN" "TWHT"`"TLGN"s/     .ss  h  m  myy/ /s`"TWHT"`  " TNRM,
	""TLGN" `s:     `oo  s  m  Myy+-o:`   " TNRM,
	""TLGN" `oo      :+sdoohyoydyso/.     " TNRM,
	""TLGN"  :o.      .:////////++:       " TNRM,
	""TLGN"  `/++        "TWHT"-:::::-          " TNRM,
	""TLGN"   "TWHT"`"TLGN"++-                        " TNRM,
	""TLGN"    "TWHT"`"TLGN"/+-                       " TNRM,
	""TLGN"      "TWHT"."TLGN"+/.                     " TNRM,
	""TLGN"        "TWHT"."TLGN":+-.                  " TNRM,
	""TLGN"           `--.``              " TNRM,
	"                               " TNRM
};

/* tested, working */
char* ubuntu_logo[] =
{
	""TLRD"                          ./+o+-       " TNRM,
	""TWHT"                  yyyyy- "TLRD"-yyyyyy+     " TNRM,
	""TWHT"               "TWHT"://+//////"TLRD"-yyyyyyo     " TNRM,
	""TYLW"           .++ "TWHT".:/++++++/-"TLRD".+sss/`     " TNRM,
	""TYLW"         .:++o:  "TWHT"/++++++++/:--:/-     " TNRM,
	""TYLW"        o:+o+:++."TWHT"`..```.-/oo+++++/    " TNRM,
	""TYLW"       .:+o:+o/."TWHT"          `+sssoo+/   " TNRM,
	""TWHT"  .++/+:"TYLW"+oo+o:`"TWHT"             /sssooo.  " TNRM,
	""TWHT" /+++//+:"TYLW"`oo+o"TWHT"               /::--:.  " TNRM,
	""TWHT" +/+o+++"TYLW"`o++o"TLRD"               ++////.   " TNRM,
	""TWHT"  .++.o+"TYLW"++oo+:`"TLRD"             /dddhhh.  " TNRM,
	""TYLW"       .+.o+oo:."TLRD"          `oddhhhh+   " TNRM,
	""TYLW"        +.++o+o``-``"TLRD"``.:ohdhhhhh+     " TNRM,
	""TYLW"         `:o+++ "TLRD"`ohhhhhhhhyo++os:     " TNRM,
	""TYLW"           .o:"TLRD"`.syhhhhhhh/"TYLW".oo++o`     " TNRM,
	""TLRD"               /osyyyyyyo"TYLW"++ooo+++/    " TNRM,
	""TLRD"                   ````` "TYLW"+oo+++o:    " TNRM,
	""TYLW"                          `oo++.      " TNRM
};

/* tested, working */
char* debian_logo[] =
{
	"  "TWHT"       _,met$$$$$gg.           " TNRM,
	"  "TWHT"    ,g$$$$$$$$$$$$$$$P.       " TNRM,
	"  "TWHT"  ,g$$P\"\"       \"\"\"Y$$.\".     " TNRM,
	"  "TWHT" ,$$P'              `$$$.     " TNRM,
	"  "TWHT"',$$P       ,ggs.     `$$b:   " TNRM,
	"  "TWHT"`d$$'     ,$P\"\'   "TLRD"."TWHT"    $$$    " TNRM,
	"  "TWHT" $$P      d$\'     "TLRD","TWHT"    $$P    " TNRM,
	"  "TWHT" $$:      $$.   "TLRD"-"TWHT"    ,d$$'    " TNRM,
	"  "TWHT" $$;      Y$b._   _,d$P'     " TNRM,
	"  "TWHT" Y$$.    "TLRD"`."TWHT"`\"Y$$$$P\"'         " TNRM,
	"  "TWHT" `$$b      "TLRD"\"-.__              " TNRM,
	"  "TWHT"  `Y$$                        " TNRM,
	"  "TWHT"   `Y$$.                      " TNRM,
	"  "TWHT"     `$$b.                    " TNRM,
	"  "TWHT"       `Y$$b.                 " TNRM,
	"  "TWHT"          `\"Y$b._             " TNRM,
	"  "TWHT"              `\"\"\"\"           " TNRM,
	"                                " TNRM
};

/* tested, working */
char* crunchbang_logo[] =
{
	"                                       "TNRM"",
	"         "TWHT"███        "TWHT"███          "TWHT"███  "TNRM"",
	"         "TWHT"███        "TWHT"███          "TWHT"███  "TNRM"",
	"         "TWHT"███        "TWHT"███          "TWHT"███  "TNRM"",
	"         "TWHT"███        "TWHT"███          "TWHT"███  "TNRM"",
	"  "TWHT"████████████████████████████   "TWHT"███  "TNRM"",
	"  "TWHT"████████████████████████████   "TWHT"███  "TNRM"",
	"         "TWHT"███        "TWHT"███          "TWHT"███  "TNRM"",
	"         "TWHT"███        "TWHT"███          "TWHT"███  "TNRM"",
	"         "TWHT"███        "TWHT"███          "TWHT"███  "TNRM"",
	"         "TWHT"███        "TWHT"███          "TWHT"███  "TNRM"",
	"  "TWHT"████████████████████████████   "TWHT"███  "TNRM"",
	"  "TWHT"████████████████████████████   "TWHT"███  "TNRM"",
	"         "TWHT"███        "TWHT"███               "TNRM"",
	"         "TWHT"███        "TWHT"███               "TNRM"",
	"         "TWHT"███        "TWHT"███          "TWHT"███  "TNRM"",
	"         "TWHT"███        "TWHT"███          "TWHT"███  "TNRM"",
	"                                      "TNRM""
};

/* tested, working */
char* gentoo_logo[] =
{
	""TLPR"         -/oyddmdhs+:.                " TNRM,
	""TLPR"     -o"TWHT"dNMMMMMMMMNNmhy+"TLPR"-`            " TNRM,
	""TLPR"   -y"TWHT"NMMMMMMMMMMMNNNmmdhy"TLPR"+-          " TNRM,
	""TLPR" `o"TWHT"mMMMMMMMMMMMMNmdmmmmddhhy"TLPR"/`       " TNRM,
	""TLPR" om"TWHT"MMMMMMMMMMMN"TLPR"hhyyyo"TWHT"hmdddhhhd"TLPR"o`     " TNRM,
	""TLPR".y"TWHT"dMMMMMMMMMMd"TLPR"hs++so/s"TWHT"mdddhhhhdm"TLPR"+`   " TNRM,
	""TLPR" oy"TWHT"hdmNMMMMMMMN"TLPR"dyooy"TWHT"dmddddhhhhyhN"TLPR"d.  " TNRM,
	""TLPR"  :o"TWHT"yhhdNNMMMMMMMNNNmmdddhhhhhyym"TLPR"Mh  " TNRM,
	""TLPR"    .:"TWHT"+sydNMMMMMNNNmmmdddhhhhhhmM"TLPR"my  " TNRM,
	""TLPR"       /m"TWHT"MMMMMMNNNmmmdddhhhhhmMNh"TLPR"s:  " TNRM,
	""TLPR"   `o"TWHT"NMMMMMMMNNNmmmddddhhdmMNhs"TLPR"+`   " TNRM,
	""TLPR"  `s"TWHT"NMMMMMMMMNNNmmmdddddmNMmhs"TLPR"/.     " TNRM,
	""TLPR" /N"TWHT"MMMMMMMMNNNNmmmdddmNMNdso"TLPR":`       " TNRM,
	""TLPR"+M"TWHT"MMMMMMNNNNNmmmmdmNMNdso"TLPR"/-          " TNRM,
	""TLPR"yM"TWHT"MNNNNNNNmmmmmNNMmhs+/"TLPR"-`              " TNRM,
	""TLPR"/h"TWHT"MMNNNNNNNNMNdhs++/"TLPR"-`               " TNRM,
	""TLPR"`/"TWHT"ohdmmddhys+++/:"TLPR".`                  " TNRM,
	""TLPR"  `-//////:--.                       " TNRM
};

/* tested, working */
char* funtoo_logo[] =
{
	"                                                     " TNRM,
	"                                                    " TNRM,
	"                                                    " TNRM,
	"                                                    " TNRM,
	TWHT "     _______               ____                     " TNRM,
	TWHT "    /MMMMMMM/             /MMMM| _____  _____       " TNRM,
	TWHT " __/M"TLPR".MMM."TWHT"M/_____________|M"TLPR".M"TWHT"MM|/MMMMM\\/MMMMM\\      " TNRM,
	TWHT "|MMMM"TLPR"MM'"TWHT"MMMMMMMMMMMMMMMMMMM"TLPR"MM"TWHT"MMMM"TLPR".MMMM..MMMM."TWHT"MM\\    " TNRM,
	TWHT "|MM"TLPR"MMMMMMM"TWHT"/m"TLPR"MMMMMMMMMMMMMMMMMMMMMM"TWHT"MMMM"TLPR"MM"TWHT"MMMM"TLPR"MM"TWHT"MM|   " TNRM,
	TWHT "|MMMM"TLPR"MM"TWHT"MMM"TLPR"MM"TWHT"MM"TLPR"MM"TWHT"MM"TLPR"MM"TWHT"MMMMM"TLPR"\\MMM"TWHT"MMM"TLPR"MM"TWHT"MMMM"TLPR"MM"TWHT"MMMM"TLPR"MM"TWHT"MM|   " TNRM,
	TWHT "  |MM"TLPR"MM"TWHT"MMM"TLPR"MM"TWHT"MM"TLPR"MM"TWHT"MM"TLPR"MM"TWHT"MM"TLPR"MM"TWHT"MM"TLPR"MMM"TWHT"MMMM"TLPR"'MMMM''MMMM'"TWHT"MM/    " TNRM,
	TWHT "  |MM"TLPR"MM"TWHT"MMM"TLPR"MM"TWHT"MM"TLPR"MM"TWHT"MM"TLPR"MM"TWHT"MM"TLPR"MM"TWHT"MM"TLPR"MMM"TWHT"MMM\\MMMMM/\\MMMMM/      " TNRM,
	TWHT "  |MM"TLPR"MM"TWHT"MMM"TLPR"MM"TWHT"MMMMMM"TLPR"MM"TWHT"MM"TLPR"MM"TWHT"MM"TLPR"MMMMM'"TWHT"M|                  " TNRM,
	TWHT "  |MM"TLPR"MM"TWHT"MMM"TLPR"MMMMMMMMMMMMMMMMM MM'"TWHT"M/                   " TNRM,
	TWHT "  |MMMMMMMMMMMMMMMMMMMMMMMMMMMM/                    " TNRM,
	"                                                    " TNRM,
	"                                                    " TNRM,
	"                                                    " TNRM
};

/* tested, working */
char* fedora_logo[] =
{
	""TLBL"           :/------------://          " TNRM,
	""TLBL"        :------------------://       " TNRM,
	""TLBL"      :-----------"TWHT"/shhdhyo/"TLBL"-://      " TNRM,
	""TLBL"    /-----------"TWHT"omMMMNNNMMMd/"TLBL"-:/     " TNRM,
	""TLBL"   :-----------"TWHT"sMMMdo:/"TLBL"       -:/    " TNRM,
	""TLBL"  :-----------"TWHT":MMMd"TLBL"-------    --:/   " TNRM,
	""TLBL"  /-----------"TWHT":MMMy"TLBL"-------    ---/   " TNRM,
	""TLBL" :------    --"TWHT"/+MMMh/"TLBL"--        ---:  " TNRM,
	""TLBL" :---     "TWHT"oNMMMMMMMMMNho"TLBL"     -----:  " TNRM,
	""TLBL" :--      "TWHT"+shhhMMMmhhy++"TLBL"   ------:   " TNRM,
	""TLBL" :-      -----"TWHT":MMMy"TLBL"--------------/   " TNRM,
	""TLBL" :-     ------"TWHT"/MMMy"TLBL"-------------:    " TNRM,
	""TLBL" :-      ----"TWHT"/hMMM+"TLBL"------------:     " TNRM,
	""TLBL" :--"TWHT":dMMNdhhdNMMNo"TLBL"-----------:       " TNRM,
	""TLBL" :---"TWHT":sdNMMMMNds:"TLBL"----------:         " TNRM,
	""TLBL" :------"TWHT":://:"TLBL"-----------://          " TNRM,
	""TLBL" :--------------------://            " TNRM,
	"                                     " TNRM
};

/* tested, working */
char* freebsd_logo[] =
{
	"                                      " TNRM,
	"   "TWHT"```                        "TLRD"`      " TNRM,
	"  "TWHT"` `.....---..."TLRD"....--.```   -/      " TNRM,     
	"  "TWHT"+o   .--`         "TLRD"/y:`      +.     " TNRM, 
	"  "TWHT" yo`:.            "TLRD":o      `+-      " TNRM,       
	"    "TWHT"y/               "TLRD"-/`   -o/       " TNRM,      
	"   "TWHT".-                  "TLRD"::/sy+:.      " TNRM,       
	"   "TWHT"/                     "TLRD"`--  /      " TNRM,         
	"  "TWHT"`:                          "TLRD":`     " TNRM,        
	"  "TWHT"`:                          "TLRD":`     " TNRM,       
	"   "TWHT"/                          "TLRD"/      " TNRM,     
	"   "TWHT".-                        "TLRD"-.      " TNRM,         
	"    "TWHT"--                      "TLRD"-.       " TNRM,         
	"     "TWHT"`:`                  "TLRD"`:`        " TNRM,      
	"       "TLRD".--             `--.          " TNRM,  
	"         "TLRD" .---.....----.             " TNRM,            
	"                                     " TNRM,              
	"                                     " TNRM 
};

/* tested, working */
/* NOTE: has 23 lines, not 18 */
char* openbsd_logo[] = 
{
	"                                       "TLCY" _      "TNRM"",
	"                                       "TLCY"(_)      "TNRM"",
	""TYLW"              |    .                            "TNRM"",
	""TYLW"          .   |L  /|   .         "TLCY" _      " TNRM,
	""TYLW"      _ . |\\ _| \\--+._/| .       "TLCY"(_)    " TNRM,
	""TYLW"     / ||\\| Y J  )   / |/| ./           " TNRM,
	""TYLW"    J  |)'( |        \\` F\\`.'/       "TLCY" _   " TNRM,
	""TYLW"  -<|  F         __     .-<        "TLCY"(_)  " TNRM,
	""TYLW"    | /       .-'"TLCY". "TYLW"\\`.  /"TLCY"-. "TYLW"L___         " TNRM,
	""TYLW"    J \\      <    "TLCY"\\ "TYLW" | | "TDGY"O"TLCY"\\\\"TYLW"|.-' "TLCY" _      " TNRM,
	""TYLW"  _J \\  .-    \\\\"TLCY"/ "TDGY"O "TLCY"| "TYLW"| \\  |"TYLW"F    "TLCY"(_)     " TNRM,
	""TYLW" '-F  -<_.     \\   .-'  \\`-' L__         " TNRM,
	""TYLW"__J  _   _.     >-'  "TBRN")"TLRD"._.   "TYLW"|-'         "TNRM,
	""TYLW" \\`-|.'   /_.          "TLRD"\\_|  "TYLW" F           "TNRM,
	""TYLW"  /.-   .                _.<            " TNRM,
	""TYLW" /'    /.'             .'  \\`\\           " TNRM,
	""TYLW"  /L  /'   |/      _.-'-\\               "TNRM,
	""TYLW" /'J       ___.---'\\|                   " TNRM,
	""TYLW"   |\\  .--' V  | \\`. \\`                   "TNRM,
	""TYLW"   |/\\`. \\`-.     \\`._)                    " TNRM,
	""TYLW"      / .-.\\                            " TNRM,
	""TYLW"      \\ (  \\`\\                           "TNRM"",
	""TYLW"       \\`.\\                                  "TNRM""
};

/* tested, working */
char* dragonflybsd_logo[] =
{
	"                     "TLRD" |                     " TNRM,
	"                    "TLRD" .-.                   " TNRM,
	"                   "TYLW" ()"TLRD"I"TYLW"()                  " TNRM,
	"              "TLRD" \"==.__:-:__.==\"             " TNRM,
	"              "TLRD"\"==.__/~|~\\__.==\"            " TNRM,
	"              "TLRD"\"==._(  Y  )_.==\"            " TNRM,
	"   "TWHT".-'~~\"\"~=--...,__"TLRD"\\/|\\/"TWHT"__,...--=~\"\"~~'-. " TNRM,
	"  "TWHT"(               ..="TLRD"\\\\="TLRD"/"TWHT"=..               )" TNRM,
	"   "TWHT"\\`'-.        ,.-\"\\`;"TLRD"/=\\\\"TWHT" ;\"-.,_        .-'\\`" TNRM,
	"      "TWHT" \\`~\"-=-~\\` .-~\\` "TLRD"|=|"TWHT" \\`~-. \\`~-=-\"~\\`     " TNRM,
	"       "TWHT"     .-~\\`    /"TLRD"|=|"TWHT"\\    \\`~-.          " TNRM,
	"       "TWHT"  .~\\`       / "TLRD"|=|"TWHT" \\       \\`~.       " TNRM,
	" "TWHT"    .-~\\`        .'  "TLRD"|=|"TWHT"  \\\\\\`.        \\`~-.  " TNRM,
	" "TWHT"  (\\`     _,.-=\"\\`  "TLRD"  |=|"TWHT"    \\`\"=-.,_     \\`) " TNRM,
	" "TWHT"   \\`~\"~\"\\`        "TLRD"   |=|"TWHT"           \\`\"~\"~\\`  " TNRM,
	"                   "TLRD"  /=\\                   " TNRM,
	"                   "TLRD"  \\=/                   " TNRM,
	"                   "TLRD"   ^                    " TNRM
};

/* tested, working */
/* NOTE: has 20 lines, not 18 */
char* netbsd_logo[] =
{
	"                                  "TLRD"__,gnnnOCCCCCOObaau,_      " TNRM,
	"   "TWHT"_._                    "TLRD"__,gnnCCCCCCCCOPF\"''              " TNRM,
	"  "TWHT"(N\\\\\\\\"TLRD"XCbngg,._____.,gnnndCCCCCCCCCCCCF\"___,,,,___          " TNRM,
	"   "TWHT"\\\\N\\\\\\\\"TLRD"XCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCOOOOPYvv.     " TNRM,
	"    "TWHT"\\\\N\\\\\\\\"TLRD"XCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCPF\"''               " TNRM,
	"     "TWHT"\\\\N\\\\\\\\"TLRD"XCCCCCCCCCCCCCCCCCCCCCCCCCOF\"'                     " TNRM,
	"      "TWHT"\\\\N\\\\\\\\"TLRD"XCCCCCCCCCCCCCCCCCCCCOF\"'                         " TNRM,
	"       "TWHT"\\\\N\\\\\\\\"TLRD"XCCCCCCCCCCCCCCCPF\"'                             " TNRM,
	"        "TWHT"\\\\N\\\\\\\\"TLRD"\"PCOCCCOCCFP\"\"                                  " TNRM,
	"         "TWHT"\\\\N\\                                                " TNRM,
	"          "TWHT"\\\\N\\                                               " TNRM,
	"           "TWHT"\\\\N\\                                              " TNRM,
	"            "TWHT"\\\\NN\\                                            " TNRM,
	"             "TWHT"\\\\NN\\                                           " TNRM,
	"              "TWHT"\\\\NNA.                                         " TNRM,
	"               "TWHT"\\\\NNA,                                        " TNRM,
	"                "TWHT"\\\\NNN,                                       " TNRM,
	"                 "TWHT"\\\\NNN\\                                      " TNRM,
	"                  "TWHT"\\\\NNN\\ " TNRM,
	"                   "TWHT"\\\\NNNA" TNRM
};

/* tested, working */
char* mandriva_mandrake_logo[] =
{
	"                                          " TNRM,
	""TYLW"                         ``              " TNRM,
	""TYLW"                        `-.              " TNRM,
	""TLBL"       `               "TYLW".---              " TNRM,
	""TLBL"     -/               "TYLW"-::--`             " TNRM,
	""TLBL"   `++    "TYLW"`----...```-:::::.             " TNRM,
	""TLBL"  `os.      "TYLW".::::::::::::::-```     `  ` " TNRM,
	""TLBL"  +s+         "TYLW".::::::::::::::::---...--` " TNRM,
	""TLBL" -ss:          "TYLW"`-::::::::::::::::-.``.`` " TNRM,
	""TLBL" /ss-           "TYLW".::::::::::::-.``   `    " TNRM,
	""TLBL" +ss:          "TYLW".::::::::::::-            " TNRM,
	""TLBL" /sso         "TYLW".::::::-::::::-            " TNRM,
	""TLBL" .sss/       "TYLW"-:::-.`   .:::::            " TNRM,
	""TLBL"  /sss+.    "TYLW"..`"TLBL"  `--`    "TYLW".:::            " TNRM,
	""TLBL"   -ossso+/:://+/-`        "TYLW".:`           " TNRM,
	""TLBL"     -/+ooo+/-.              "TYLW"`           " TNRM,
	"                                         " TNRM,
	"                                         " TNRM
};

/* tested, working */
char* opensuse_logo[] =
{
	""TWHT"             .;ldkO0000Okdl;.               " TNRM,
	""TWHT"         .;d00xl:,'....';:ok00d;.           " TNRM,
	""TWHT"       .d00l'                ,o00d.         " TNRM,
	""TWHT"     .d0Kd."TLGN" :Okxol:;'.          "TWHT":O0d.       " TNRM,
	""TWHT"    'OK"TLGN"KKK0kOKKKKKKKKKKOxo:'      "TWHT"lKO'      " TNRM,
	""TWHT"   ,0K"TLGN"KKKKKKKKKKKKKKK0d:"TWHT",,,"TLGN":dx:"TWHT"    ;00,     " TNRM,
	""TWHT"  .OK"TLGN"KKKKKKKKKKKKKKKk."TWHT".oOkdl."TLGN"'0k."TWHT"   cKO.    " TNRM,
	""TWHT"  :KK"TLGN"KKKKKKKKKKKKKKK: "TWHT"kKx..od "TLGN"lKd"TWHT"   .OK:    " TNRM,
	""TWHT"  dKK"TLGN"KKKKKKKKKOx0KKKd "TWHT";0KKKO, "TLGN"kKKc"TWHT"   dKd    " TNRM,
	""TWHT"  dKK"TLGN"KKKKKKKKKK;.;oOKx,.."TWHT"'"TLGN"..;kKKK0."TWHT"  dKd    " TNRM,
	""TWHT"  :KK"TLGN"KKKKKKKKKK0o;...;cdxxOK0Oxc,.  "TWHT".0K:    " TNRM,
	""TWHT"   kKK"TLGN"KKKKKKKKKKKKK0xl;'......,cdo  "TWHT"lKk     " TNRM,
	""TWHT"   '0K"TLGN"KKKKKKKKKKKKKKKKKKKK00KKOo;  "TWHT"c00'     " TNRM,
	""TWHT"    .kK"TLGN"KKOxddxkOO00000Okxoc;'.   "TWHT".dKk.      " TNRM,
	""TWHT"      l0Ko.                    .c00l.       " TNRM,
	""TWHT"       .l0Kk:.              .;xK0l.         " TNRM,
	""TWHT"          ,lkK0xl:;,,,,;:ldO0kl,            " TNRM,
	""TWHT"              .':ldxkkkkxdl:'.              " TNRM
};

/* tested, working */
/* NOTE: has 21 lines, not 18 */
char* slackware_logo[] =
{
	""TLBL"                   :::::::",
	""TLBL"             :::::::::::::::::::               " TNRM,
	""TLBL"          :::::::::::::::::::::::::           " TNRM,
	""TLBL"        ::::::::"TWHT"cllcccccllllllll"TLBL"::::::        " TNRM,
	""TLBL"     :::::::::"TWHT"lc               dc"TLBL":::::::      " TNRM,
	""TLBL"    ::::::::"TWHT"cl   clllccllll    oc"TLBL":::::::::    " TNRM,
	""TLBL"   :::::::::"TWHT"o   lc"TLBL"::::::::"TWHT"co   oc"TLBL"::::::::::   " TNRM,
	""TLBL"  ::::::::::"TWHT"o    cccclc"TLBL":::::"TWHT"clcc"TLBL"::::::::::::  " TNRM,
	""TLBL"  :::::::::::"TWHT"lc        cclccclc"TLBL":::::::::::::  " TNRM,
	""TLBL" ::::::::::::::"TWHT"lcclcc          lc"TLBL":::::::::::: " TNRM,
	""TLBL" ::::::::::"TWHT"cclcc"TLBL":::::"TWHT"lccclc     oc"TLBL"::::::::::: " TNRM,
	""TLBL" ::::::::::"TWHT"o    l"TLBL"::::::::::"TWHT"l    lc"TLBL"::::::::::: " TNRM,
	""TLBL"  :::::"TWHT"cll"TLBL":"TWHT"o     clcllcccll     o"TLBL":::::::::::  " TNRM,
	""TLBL"  :::::"TWHT"occ"TLBL":"TWHT"o                  clc"TLBL":::::::::::  " TNRM,
	""TLBL"   ::::"TWHT"ocl"TLBL":"TWHT"ccslclccclclccclclc"TLBL":::::::::::::   " TNRM,
	""TLBL"    :::"TWHT"oclcccccccccccccllllllllllllll"TLBL":::::    " TNRM,
	""TLBL"     ::"TWHT"lcc1lcccccccccccccccccccccccco"TLBL"::::     " TNRM,
	""TLBL"       ::::::::::::::::::::::::::::::::       " TNRM,
	""TLBL"         ::::::::::::::::::::::::::::         " TNRM,
	""TLBL"            ::::::::::::::::::::::",
	""TLBL"                 ::::::::::::"
};

/* tested, working */
char* redhat_logo[] =
{
	"                                           " TNRM,
	""TLRD"              `.-..........`              " TNRM,
	""TLRD"             `////////::.`-/.             " TNRM,
	""TLRD"             -: ....-////////.            " TNRM,
	""TLRD"             //:-::///////////`           " TNRM,
	""TLRD"      `--::: `-://////////////:           " TNRM,
	""TLRD"      //////-    ``.-:///////// .`        " TNRM,
	""TLRD"      `://////:-.`    :///////::///:`     " TNRM,
	""TLRD"        .-/////////:---/////////////:     " TNRM,
	""TLRD"           .-://////////////////////.     " TNRM,
	""TWHT"          yMN+`.-"TLRD"::///////////////-`      " TNRM,
	""TWHT"       .-`:NMMNMs`  `..-------..`         " TNRM,
	""TWHT"        MN+/mMMMMMhoooyysshsss            " TNRM,
	""TWHT" MMM    MMMMMMMMMMMMMMyyddMMM+            " TNRM,
	""TWHT"  MMMM   MMMMMMMMMMMMMNdyNMMh`     hyhMMM " TNRM,
	""TWHT"   MMMMMMMMMMMMMMMMyoNNNMMM+.   MMMMMMMM  " TNRM,
	""TWHT"    MMNMMMNNMMMMMNM+ mhsMNyyyyMNMMMMsMM   " TNRM,
	"                                          " TNRM
};

/* tested, working */
/* NOTE: has 23 lines, not 18 */
char* frugalware_logo[] =
{
	""TLBL"          `++/::-.`",
	""TLBL"         /o+++++++++/::-.`",
	""TLBL"        `o+++++++++++++++o++/::-.`",
	""TLBL"        /+++++++++++++++++++++++oo++/:-.``         " TNRM,
	""TLBL"       .o+ooooooooooooooooooosssssssso++oo++/:-`  " TNRM,
	""TLBL"       ++osoooooooooooosssssssssssssyyo+++++++o:  " TNRM,
	""TLBL"      -o+ssoooooooooooosssssssssssssyyo+++++++s`  " TNRM,
	""TLBL"      o++ssoooooo++++++++++++++sssyyyyo++++++o:   " TNRM,
	""TLBL"     :o++ssoooooo"TWHT"/-------------"TLBL"+syyyyyo+++++oo    " TNRM,
	""TLBL"    `o+++ssoooooo"TWHT"/-----"TLBL"+++++ooosyyyyyyo++++os:    " TNRM,
	""TLBL"    /o+++ssoooooo"TWHT"/-----"TLBL"ooooooosyyyyyyyo+oooss     " TNRM,
	""TLBL"   .o++++ssooooos"TWHT"/------------"TLBL"syyyyyyhsosssy-     " TNRM,
	""TLBL"   ++++++ssooooss"TWHT"/-----"TLBL"+++++ooyyhhhhhdssssso      " TNRM,
	""TLBL"  -s+++++syssssss"TWHT"/-----"TLBL"yyhhhhhhhhhhhddssssy.      " TNRM,
	""TLBL"  sooooooyhyyyyyh"TWHT"/-----"TLBL"hhhhhhhhhhhddddyssy+       " TNRM,
	""TLBL" :yooooooyhyyyhhhyyyyyyhhhhhhhhhhdddddyssy`       " TNRM,
	""TLBL" yoooooooyhyyhhhhhhhhhhhhhhhhhhhddddddysy/        " TNRM,
	""TLBL"-ysooooooydhhhhhhhhhhhddddddddddddddddssy         " TNRM,
	""TLBL" .-:/+osssyyyysyyyyyyyyyyyyyyyyyyyyyyssy:         " TNRM,
	""TLBL"       ``.-/+oosysssssssssssssssssssssss          " TNRM,
	""TLBL"               ``.:/+osyysssssssssssssh.          " TNRM,
	""TLBL"                        `-:/+osyyssssyo",
	""TLBL"                                .-:+++`" TNRM
};

/* tested, working */
/* NOTE: has 19 lines, not 18 */
char* peppermint_logo[] =
{
	""TLRD"             8ZZZZZZ"TWHT"MMMMM               " TNRM,
	""TLRD"          .ZZZZZZZZZ"TWHT"MMMMMMM.           " TNRM,
	""TWHT"        MM"TLRD"ZZZZZZZZZ"TWHT"MMMMMMM"TLRD"ZZZZ         " TNRM,
	""TWHT"      MMMMM"TLRD"ZZZZZZZZ"TWHT"MMMMM"TLRD"ZZZZZZZM       " TNRM,
	""TWHT"     MMMMMMM"TLRD"ZZZZZZZ"TWHT"MMMM"TLRD"ZZZZZZZZZ.      " TNRM,
	""TWHT"    MMMMMMMMM"TLRD"ZZZZZZ"TWHT"MMM"TLRD"ZZZZZZZZZZZI     " TNRM,
	""TWHT"   MMMMMMMMMMM"TLRD"ZZZZZZ"TWHT"MM"TLRD"ZZZZZZZZZZ"TWHT"MMM    " TNRM,
	""TLRD"   .ZZZ"TWHT"MMMMMMMMMM"TLRD"IZZ"TWHT"MM"TLRD"ZZZZZ"TWHT"MMMMMMMMM   " TNRM,
	""TLRD"   ZZZZZZZ"TWHT"MMMMMMMM"TLRD"ZZ"TWHT"M"TLRD"ZZZZ"TWHT"MMMMMMMMMMM   " TNRM,
	""TLRD"   ZZZZZZZZZZZZZZZZ"TWHT"M"TLRD"Z"TWHT"MMMMMMMMMMMMMMM   " TNRM,
	""TLRD"   .ZZZZZZZZZZZZZ"TWHT"MMM"TLRD"Z"TWHT"M"TLRD"ZZZZZZZZZZ"TWHT"MMMM   " TNRM,
	""TLRD"   .ZZZZZZZZZZZ"TWHT"MMM"TLRD"7ZZ"TWHT"MM"TLRD"ZZZZZZZZZZ7"TWHT"M    " TNRM,
	""TLRD"    ZZZZZZZZZ"TWHT"MMMM"TLRD"ZZZZ"TWHT"MMMM"TLRD"ZZZZZZZ77     " TNRM,
	""TWHT"     MMMMMMMMMMMM"TLRD"ZZZZZ"TWHT"MMMM"TLRD"ZZZZZ77      " TNRM,
	""TWHT"     MMMMMMMMMM"TLRD"7ZZZZZZ"TWHT"MMMMM"TLRD"ZZ77       " TNRM,
	""TWHT"       .MMMMMMM"TLRD"ZZZZZZZZ"TWHT"MMMMM"TLRD"Z7Z        " TNRM,
	""TWHT"         MMMMM"TLRD"ZZZZZZZZZ"TWHT"MMMMMMM         " TNRM,
	""TLRD"           NZZZZZZZZZZZ"TWHT"MMMMM           " TNRM,
	""TLRD"              ZZZZZZZZZ"TWHT"MM" TNRM
};

/* tested, working */
char* solusos_logo[] =
{
	""TWHT"               e         e      " TNRM,
	""TWHT"             eee       ee      " TNRM,
	""TWHT"            eeee     eee       " TNRM,
	""TDGY"        wwwwwwwww"TWHT"eeeeee        " TNRM,
	""TDGY"     wwwwwwwwwwwwwww"TWHT"eee        " TNRM,
	""TDGY"   wwwwwwwwwwwwwwwwwww"TWHT"eeeeeeee " TNRM,
	""TDGY"  wwwww     "TWHT"eeeee"TDGY"wwwwww"TWHT"eeee    " TNRM,
	""TDGY" www          "TWHT"eeee"TDGY"wwwwww"TWHT"e      " TNRM,
	""TDGY" ww             "TWHT"ee"TDGY"wwwwww       " TNRM,
	""TDGY" w                 wwwww       " TNRM,
	""TDGY"                   wwwww       " TNRM,
	""TDGY"                  wwwww        " TNRM,
	""TDGY"                 wwwww         " TNRM,
	""TDGY"                wwww           " TNRM,
	""TDGY"               wwww            " TNRM,
	""TDGY"             wwww              " TNRM,
	""TDGY"           www                 " TNRM,
	""TDGY"         ww                    " TNRM
};

/* tested, working */
char* mageia_logo[] = 
{
	""TLCY"               .°°.               " TNRM,
	""TLCY"                °°   .°°.        " TNRM,
	""TLCY"                .°°°. °°         " TNRM,
	""TLCY"                .   .            " TNRM,
	""TLCY"                 °°° .°°°.       " TNRM,
	""TLCY"             .°°°.   '___'       " TNRM,
	""TWHT"            ."TLCY"'___'     "TWHT"   .      " TNRM,
	""TWHT"          :dkxc;'.  ..,cxkd;     " TNRM,
	""TWHT"        .dkk. kkkkkkkkkk .kkd.   " TNRM,
	""TWHT"       .dkk.  ';cloolc;.  .kkd   " TNRM,
	""TWHT"       ckk.                .kk;  " TNRM,
	""TWHT"       xO:                  cOd  " TNRM,
	""TWHT"       xO:                  lOd  " TNRM,
	""TWHT"       lOO.                .OO:  " TNRM,
	""TWHT"       .k00.              .00x   " TNRM,
	""TWHT"        .k00;            ;00O.   " TNRM,
	""TWHT"         .lO0Kc;,,,,,,;c0KOc.    " TNRM,
	""TWHT"            ;d00KKKKKK00d;       " TNRM,
	""TWHT"               .,KKKK,.            " TNRM
};

/* tested, working */
char* parabolagnu_linuxlibre_logo[] = 
{
	"                                  " TNRM,
	""TLPR"              eeeeeeeee          " TNRM,
	""TLPR"          eeeeeeeeeeeeeee        " TNRM,
	""TLPR"       eeeeee"TWHT"//////////"TLPR"eeeee     " TNRM,
	""TLPR"     eeeee"TWHT"///////////////"TLPR"eeeee   " TNRM,
	""TLPR"   eeeee"TWHT"///           ////"TLPR"eeee   " TNRM,
	""TLPR"  eeee"TWHT"//              ///"TLPR"eeeee   " TNRM,
	""TLPR" eee                 "TWHT"///"TLPR"eeeee    " TNRM,
	""TLPR"ee                  "TWHT"//"TLPR"eeeeee     " TNRM,
	""TLPR"e                  "TWHT"/"TLPR"eeeeeee      " TNRM,
	""TLPR"                  eeeeeee        " TNRM,
	""TLPR"                 eeeeee          " TNRM,
	""TLPR"                eeeeee           " TNRM,
	""TLPR"               eeeee             " TNRM,
	""TLPR"              eeee               " TNRM,
	""TLPR"            eee                  " TNRM,
	""TLPR"           ee                    " TNRM,
	""TLPR"          e                      " TNRM
};

/* tested, working */
char* viperr_logo[] =
{
	""TWHT"    wwzapd         dlzazw       " TNRM,
	""TWHT"   an"TDGY"#"TWHT"zncmqzepweeirzpas"TDGY"#"TWHT"xz     " TNRM,
	""TWHT" apez"TDGY"##"TWHT"qzdkawweemvmzdm"TDGY"##"TWHT"dcmv   " TNRM,
	""TWHT"zwepd"TDGY"####"TWHT"qzdweewksza"TDGY"####"TWHT"ezqpa  " TNRM,
	""TWHT"ezqpdkapeifjeeazezqpdkazdkwqz  " TNRM,
	""TWHT" ezqpdksz"TDGY"##"TWHT"wepuizp"TDGY"##"TWHT"wzeiapdk   " TNRM,
	""TWHT"  zqpakdpa"TDGY"#"TWHT"azwewep"TDGY"#"TWHT"zqpdkqze    " TNRM,
	""TWHT"    apqxalqpewenwazqmzazq      " TNRM,
	""TWHT"     mn"TDGY"##"TWHT"=="TDGY"#######"TWHT"=="TDGY"##"TWHT"qp       " TNRM,
	""TWHT"      qw"TDGY"##"TWHT"="TDGY"#######"TWHT"="TDGY"##"TWHT"zl        " TNRM,
	""TWHT"      z0"TDGY"######"TWHT"="TDGY"######"TWHT"0a        " TNRM,
	""TWHT"       qp"TDGY"#####"TWHT"="TDGY"#####"TWHT"mq         " TNRM,
	""TWHT"       az"TDGY"####"TWHT"==="TDGY"####"TWHT"mn         " TNRM,
	""TWHT"        ap"TDGY"#########"TWHT"qz          " TNRM,
	""TWHT"         9qlzskwdewz           " TNRM,
	""TWHT"          zqwpakaiw            " TNRM,
	""TWHT"            qoqpe              " TNRM,
	"                               " TNRM
};

/* tested, working */
char* linuxdeepin_logo[] =
{
	""TLGN"  eeeeeeeeeeeeeeeeeeeeeeeeeeee    " TNRM,
	""TLGN" eee  eeeeeee          eeeeeeee  " TNRM,
	""TLGN"ee   eeeeeeeee      eeeeeeeee ee " TNRM,
	""TLGN"e   eeeeeeeee     eeeeeeeee    e " TNRM,
	""TLGN"e   eeeeeee    eeeeeeeeee      e " TNRM,
	""TLGN"e   eeeeee    eeeee            e " TNRM,
	""TLGN"e    eeeee    eee  eee         e " TNRM,
	""TLGN"e     eeeee   ee eeeeee        e " TNRM,
	""TLGN"e      eeeee   eee   eee       e " TNRM,
	""TLGN"e       eeeeeeeeee  eeee       e " TNRM,
	""TLGN"e         eeeee    eeee        e " TNRM,
	""TLGN"e               eeeeee         e " TNRM,
	""TLGN"e            eeeeeee           e " TNRM,
	""TLGN"e eee     eeeeeeee             e " TNRM,
	""TLGN"eeeeeeeeeeeeeeee               e " TNRM,
	""TLGN"eeeeeeeeeeeee                 ee " TNRM,
	""TLGN" eeeeeeeeeee                eee  " TNRM,
	""TLGN"  eeeeeeeeeeeeeeeeeeeeeeeeeeee   " TNRM,
	"                                 " TNRM
};

/* tested, working */
char* chakra_logo[] =
{
	""TLBL"      _ _ _        \"kkkkkkkk.          " TNRM,
	""TLBL"    ,kkkkkkkk.,    \'kkkkkkkkk,        " TNRM,
	""TLBL"    ,kkkkkkkkkkkk., \'kkkkkkkkk.       " TNRM,
	""TLBL"   ,kkkkkkkkkkkkkkkk,\'kkkkkkkk,       " TNRM,
	""TLBL"  ,kkkkkkkkkkkkkkkkkkk\'kkkkkkk.       " TNRM,
	""TLBL"   \"\'\'\"\'\'\',;::,,\"\'\'kkk\'\'kkkkk;   __   " TNRM,
	""TLBL"       ,kkkkkkkkkk, \"k\'\'kkkkk\' ,kkkk  " TNRM,
	""TLBL"     ,kkkkkkk\' ., \' .: \'kkkk\',kkkkkk  " TNRM,
	""TLBL"   ,kkkkkkkk\'.k\'   ,  ,kkkk;kkkkkkkkk " TNRM,
	""TLBL"  ,kkkkkkkk\';kk \'k  \"\'k\',kkkkkkkkkkkk " TNRM,
	""TLBL" .kkkkkkkkk.kkkk.\'kkkkkkkkkkkkkkkkkk\' " TNRM,
	""TLBL" ;kkkkkkkk\'\'kkkkkk;\'kkkkkkkkkkkkk\'\'   " TNRM,
	""TLBL" \'kkkkkkk; \'kkkkkkkk.,\"\"\'\'\"\'\'\"\"       " TNRM,
	""TLBL"   \'\'kkkk;  \'kkkkkkkkkk.,             " TNRM,
	""TLBL"      \';\'    \'kkkkkkkkkkkk.,          " TNRM,
	""TLBL"              ';kkkkkkkkkk\'           " TNRM,
	""TLBL"                ';kkkkkk\'             " TNRM,
	""TLBL"                   \"\'\'\"               " TNRM
};

/* tested, working */
/* NOTE: has 21 lines, not 18 */
char* fuduntu_logo[] =
{
	""TDGY"       `dwoapfjsod`"TYLW"           `dwoapfjsod`",
	""TDGY"    `xdwdsfasdfjaapz`"TYLW"       `dwdsfasdfjaapzx`     " TNRM,
	""TDGY"  `wadladfladlafsozmm`"TYLW"     `wadladfladlafsozmm`  " TNRM,
	""TDGY" `aodowpwafjwodisosoaas`"TYLW" `odowpwafjwodisosoaaso` " TNRM,
	""TDGY" `adowofaowiefawodpmmxs`"TYLW" `dowofaowiefawodpmmxso` " TNRM,
	""TDGY" `asdjafoweiafdoafojffw`"TYLW" `sdjafoweiafdoafojffwq` " TNRM,
	""TDGY"  `dasdfjalsdfjasdlfjdd`"TYLW" `asdfjalsdfjasdlfjdda`  " TNRM,
	""TDGY"   `dddwdsfasdfjaapzxaw`"TYLW" `ddwdsfasdfjaapzxawo`   " TNRM,
	""TDGY"     `dddwoapfjsowzocmw`"TYLW" `ddwoapfjsowzocmwp`     " TNRM,
	""TDGY"       `ddasowjfowiejao`"TYLW" `dasowjfowiejaow`       " TNRM,
	"                                                 " TNRM,
	""TLRD"       `ddasowjfowiejao`"TWHT" `dasowjfowiejaow`       " TNRM,
	""TLRD"     `dddwoapfjsowzocmw`"TWHT" `ddwoapfjsowzocmwp`     " TNRM,
	""TLRD"   `dddwdsfasdfjaapzxaw`"TWHT" `ddwdsfasdfjaapzxawo`   " TNRM,
	""TLRD"  `dasdfjalsdfjasdlfjdd`"TWHT" `asdfjalsdfjasdlfjdda`  " TNRM,
	""TLRD" `asdjafoweiafdoafojffw`"TWHT" `sdjafoweiafdoafojffwq` " TNRM,
	""TLRD" `adowofaowiefawodpmmxs`"TWHT" `dowofaowiefawodpmmxso` " TNRM,
	""TLRD" `aodowpwafjwodisosoaas`"TWHT" `odowpwafjwodisosoaaso` " TNRM,
	""TLRD"   `wadladfladlafsozmm`"TWHT"     `wadladfladlafsozmm` " TNRM,
	""TLRD"     `dwdsfasdfjaapzx`"TWHT"       `dwdsfasdfjaapzx`" TNRM,
	""TLRD"        `woapfjsod`"TWHT"             `woapfjsod`" TNRM
};

/* tested, working */
/* NOTE: has 16 lines, not 18 */
char* macosx_logo[] =
{
	"\n"TGRN"                 -/+:.          " TNRM,
	""TGRN"                :++++.         " TNRM,
	""TGRN"               /+++/.          " TNRM,
	""TGRN"       .:-::- .+/:-``.::-      " TNRM,
	""TGRN"    .:/++++++/::::/++++++/:`   " TNRM,
	""TBRN"  .:///////////////////////:`  " TNRM,
	""TBRN"  ////////////////////////`    " TNRM,
	""TLRD" -+++++++++++++++++++++++`     " TNRM,
	""TLRD" /++++++++++++++++++++++/      " TNRM,
	""TRED" /sssssssssssssssssssssss.     " TNRM,
	""TRED" :ssssssssssssssssssssssss-    " TNRM,
	""TPUR"  osssssssssssssssssssssssso/` " TNRM,
	""TPUR"  `syyyyyyyyyyyyyyyyyyyyyyyy+` " TNRM,
	""TBLU"   `ossssssssssssssssssssss/   " TNRM,
	""TBLU"     :ooooooooooooooooooo+.    " TNRM,
	""TBLU"      `:+oo+/:-..-:/+o+/-      "TNRM"",
};

/* tested, working */
/* NOTE: has 16 lines, not 18 */
char* windows_logo[] =
{
	""TLRD"        ,.=:!!t3Z3z.,                 " TNRM,
	""TLRD"       :tt:::tt333EE3                " TNRM,
	""TLRD"       Et:::ztt33EEEL"TLGN" @Ee.,      .., " TNRM,
	""TLRD"      ;tt:::tt333EE7"TLGN" ;EEEEEEttttt33# " TNRM,
	""TLRD"     :Et:::zt333EEQ."TLGN" $EEEEEttttt33QL " TNRM,
	""TLRD"     it::::tt333EEF"TLGN" @EEEEEEttttt33F  " TNRM,
	""TLRD"    ;3=*^```\"*4EEV"TLGN" :EEEEEEttttt33@.  " TNRM,
	""TLBL"    ,.=::::!t=., "TLRD"`"TLGN" @EEEEEEtttz33QF   " TNRM,
	""TLBL"   ;::::::::zt33)"TLGN"   \"4EEEtttji3P*    " TNRM,
	""TLBL"  :t::::::::tt33."TYLW":Z3z.."TLGN"  ``"TYLW" ,..g.    " TNRM,
	""TLBL"  i::::::::zt33F"TYLW" AEEEtttt::::ztF     " TNRM,
	""TLBL" ;:::::::::t33V"TYLW" ;EEEttttt::::t3      " TNRM,
	""TLBL" E::::::::zt33L"TYLW" @EEEtttt::::z3F      " TNRM,
	""TLBL"{3=*^```\"*4E3)"TYLW" ;EEEtttt:::::tZ`      " TNRM,
	""TLBL"             `"TYLW" :EEEEtttt::::z7       " TNRM,
	""TYLW"                 \"VEzjt:;;z>*`       " TNRM
};

/* tested, working */
char* trisquel_logo[] =
{
	""TLBL"                          ▄▄▄▄▄▄       " TNRM,
	""TLBL"                       ▄█████████▄    " TNRM,
	""TLBL"       ▄▄▄▄▄▄         ████▀   ▀████   " TNRM,
	""TLBL"    ▄██████████▄     ████▀   ▄▄ ▀███  " TNRM,
	""TLBL"  ▄███▀▀   ▀▀████     ███▄   ▄█   ███ " TNRM,
	""TLBL" ▄███   ▄▄▄   ████▄    ▀██████   ▄███ " TNRM,
	""TLBL" ███   █▀▀██▄  █████▄     ▀▀   ▄████  " TNRM,
	""TLBL" ▀███      ███  ███████▄▄  ▄▄██████   " TNRM,
	""TLBL"  ▀███▄   ▄███  █████████████"TLCY"████▀    " TNRM,
	""TLBL"   ▀█████████    ███████"TLCY"███▀▀▀        " TNRM,
	""TLBL"     ▀▀███▀▀     ██"TLCY"████▀▀             " TNRM,
	""TLCY"                ██████▀   ▄▄▄▄        " TNRM,
	""TLCY"               █████▀   ████████      " TNRM,
	""TLCY"               █████   ███▀  ▀███     " TNRM,
	""TLCY"                ████▄   ██▄▄▄  ███    " TNRM,
	""TLCY"                 █████▄   ▀▀  ▄██     " TNRM,
	""TLCY"                   ██████▄▄▄████      " TNRM,
	""TLCY"                      ▀▀█████▀▀       " TNRM
};

/* tested, working */
char* manjaro_logo[] =
{
	""TLGN" ██████████████████  ████████    " TNRM,
	""TLGN" ██████████████████  ████████    " TNRM,
	""TLGN" ██████████████████  ████████    " TNRM,
	""TLGN" ██████████████████  ████████    " TNRM,
	""TLGN" ████████            ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	""TLGN"           ████████  ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	""TLGN" ████████  ████████  ████████    " TNRM,
	"                                 " TNRM
};

/* tested, working */
char* elementaryos_logo[] =
{
	"                                  ",
	""TWHT"           $?77777$$$IO          " TNRM,
	""TWHT"        $III777ZZZZ$$$ZZ$8       " TNRM,
	""TWHT"      ZI777           OZZZ$      " TNRM,
	""TWHT"     Z777             O7ZZO8     " TNRM,
	""TWHT"    Z777            O$ZZZ8       " TNRM,
	""TWHT"    I$$           O$ZZZD         " TNRM,
	""TWHT"   0$$O         O$$ZZ            " TNRM,
	""TWHT"   0$$O       8$$$$              " TNRM,
	""TWHT"   0$$O     8$$$$                " TNRM,
	""TWHT"    $ZZ   O$$ZZ           D      " TNRM,
	""TWHT"     ZZZ8ZZZZ             O88    " TNRM,
	""TWHT"     DZZZZ8             D888     " TNRM,
	""TWHT"       ZZZZDMMMMMMMMMMDO888      " TNRM,
	""TWHT"         ZOOOOOOOOOOOO888        " TNRM,
	""TWHT"           N8OOOOOOO8D           " TNRM,
	"                                 " TNRM,
	"                                 " TNRM
};

/* tested, working */
/* NOTE: has 20 lines, not 18 */
char* scientificlinux_logo[] =
{
	""TLBL"                  =/;;/-" TNRM,
	""TLBL"                 +:    //                    " TNRM,
	""TLBL"                /;      /;                  " TNRM,
	""TLBL"               -X        H.                 " TNRM,
	""TLBL" .//;;;:;;-,   X=        :+   .-;:=;:;#;.   " TNRM,
	""TLBL" M-       ,=;;;#:,      ,:#;;:=,       ,@   " TNRM,
	""TLBL" :#           :#.=/++++/=.$=           #=   " TNRM,
	""TLBL"  ,#;         #/:+/;,,/++:+/         ;+.    " TNRM,
	""TLBL"    ,+/.    ,;@+,        ,#H;,    ,/+,      " TNRM,
	""TLBL"       ;+;;/= @.  "TLRD".H"TWHT"#"TLRD"#X   "TLBL"-X :///+;         " TNRM,
	""TLBL"       ;+=;;;.@,  "TWHT".X"TLRD"M"TWHT"@$.  "TLBL"=X.//;=#/.        " TNRM,
	""TLBL"    ,;:      :@#=        =$H:     .+#-      " TNRM,
	""TLBL"  ,#=         #;-///==///-//         =#,    " TNRM,
	""TLBL" ;+           :#-;;;:;;;;-X-           +:   " TNRM,
	""TLBL" @-      .-;;;;M-        =M/;;;-.      -X   " TNRM,
	""TLBL"  :;;::;;-.    #-        :+    ,-;;-;:==    " TNRM,
	""TLBL"               ,X        H.                 " TNRM,
	""TLBL"                ;/      #=                  " TNRM,
	""TLBL"                 //    +;                   " TNRM,
	""TLBL"                  '////'" TNRM
};

/* tested, working */
/* NOTE: has 20 lines, not 18 */
char* backtracklinux_logo[] =
{
	""TWHT".............."
	""TWHT"            ..,;:ccc,.                      	   " TNRM,
	""TWHT"          ......''';lxO.                        " TNRM,
	""TWHT".....''''..........,:ld;                        " TNRM,
	""TWHT"           .';;;:::;,,.x,                       " TNRM,
	""TWHT"      ..'''.            0Xxoc:,.  ...           " TNRM,
	""TWHT"  ....                ,ONkc;,;cokOdc',.         " TNRM,
	""TWHT" .                   OMo           ':"TLRD"dd"TWHT"o.       " TNRM,
	""TWHT"                    dMc               :OO;      " TNRM,
	""TWHT"                    0M.                 .:o.    " TNRM,
	""TWHT"                    ;Wd                         " TNRM,
	""TWHT"                     ;XO,                       " TNRM,
	""TWHT"                       ,d0Odlc;,..              " TNRM,
	""TWHT"                           ..',;:cdOOd::,.      " TNRM,
	""TWHT"                                    .:d;.':;.   " TNRM,
	""TWHT"                                       'd,  .'  " TNRM,
	""TWHT"                                         ;l   .." TNRM,
	""TWHT"                                          .o    " TNRM,
	""TWHT"                                            c   " TNRM,
	""TWHT"                                            .'",
	""TWHT"                                             ." TNRM
};

/* tested, working */
char* sabayon_logo[] =
{
	""TLBL"            ...........                " TNRM,
	""TLBL"         ..             ..            " TNRM,
	""TLBL"      ..                   ..         " TNRM,
	""TLBL"    ..           "TWHT"o           "TLBL"..       " TNRM,
	""TLBL"  ..            "TWHT":W'            "TLBL"..     " TNRM,
	""TLBL" ..             "TWHT".d.             "TLBL"..    " TNRM,
	""TLBL":.             "TWHT".KNO              "TLBL".:   " TNRM,
	""TLBL":.             "TWHT"cNNN.             "TLBL".:   " TNRM,
	""TLBL":              "TWHT"dXXX,              "TLBL":   " TNRM,
	""TLBL":   "TWHT".          dXXX,       .cd,   "TLBL":   " TNRM,
	""TLBL":   "TWHT"'kc ..     dKKK.    ,ll;:'    "TLBL":   " TNRM,
	""TLBL":     "TWHT".xkkxc;..dkkkc',cxkkl       "TLBL":   " TNRM,
	""TLBL":.     "TWHT".,cdddddddddddddo:.       "TLBL".:   " TNRM,
	""TLBL" ..         "TWHT":lllllll:           "TLBL"..    " TNRM,
	""TLBL"   ..         "TWHT"',,,,,          "TLBL"..      " TNRM,
	""TLBL"     ..                     ..        " TNRM,
	""TLBL"        ..               ..           " TNRM,
	""TLBL"          ...............             " TNRM
};

/* tested, working */
char* linux_logo[] =
{
	"                            " TNRM,
	"                            " TNRM,
	"                            " TNRM,
	""TDGY"         #####              " TNRM,
	""TDGY"        #######             " TNRM,
	""TDGY"        ##"TWHT"O"TDGY"#"TWHT"O"TDGY"##             " TNRM,
	""TDGY"        #"TYLW"#####"TDGY"#             " TNRM,
	""TDGY"      ##"TWHT"##"TYLW"###"TWHT"##"TDGY"##           " TNRM,
	""TDGY"     #"TWHT"##########"TDGY"##          " TNRM,
	""TDGY"    #"TWHT"############"TDGY"##         " TNRM,
	""TDGY"    #"TWHT"############"TDGY"###        " TNRM,
	""TYLW"   ##"TDGY"#"TWHT"###########"TDGY"##"TYLW"#        " TNRM,
	""TYLW" ######"TDGY"#"TWHT"#######"TDGY"#"TYLW"######      " TNRM,
	""TYLW" #######"TDGY"#"TWHT"#####"TDGY"#"TYLW"#######      " TNRM,
	""TYLW"   #####"TDGY"#######"TYLW"#####        " TNRM,
	"                            " TNRM,
	"                            " TNRM,
	"                            " TNRM
};

