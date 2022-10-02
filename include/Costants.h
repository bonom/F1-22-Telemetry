#ifndef __Costants_h__
#define __Costants_h__

#include <json/json.h>
#include <stdint.h>

#include <iostream>
#include <vector>

#if defined(_WIN64) || defined(_WIN32)
#include <string.h>
#endif

using uint64 = uint64_t;
using uint32 = uint32_t;
using uint = uint32_t;
using uint16 = uint16_t;
using uint8 = uint8_t;
using int16 = int16_t;
using int8 = int8_t;

struct seconds_t {
    double value;
};

#if defined(_WIN64) || defined(_WIN32)
    std::string OUTPUT_PATH = "Outputs\\tmp\\";
#endif
#if defined(__unix__) || defined(__APPLE__)
    std::string OUTPUT_PATH = "Outputs/tmp/";
#endif
std::string DATA_PATH = OUTPUT_PATH + "Data.json";
std::string CLASSIFICATION_PATH = OUTPUT_PATH + "Classification.json";
std::string DAMAGE_PATH = OUTPUT_PATH + "Damage.json";
std::string EVENT_PATH = OUTPUT_PATH + "Event.json";
std::string HEADER_PATH = OUTPUT_PATH + "Header.json";
std::string HISTORY_PATH = OUTPUT_PATH + "History.json";
std::string LAP_PATH = OUTPUT_PATH + "Lap.json";
std::string LOBBY_PATH = OUTPUT_PATH + "Lobby.json";
std::string MOTION_PATH = OUTPUT_PATH + "Motion.json";
std::string PARTICIPANT_PATH = OUTPUT_PATH + "Participant.json";
std::string SESSION_PATH = OUTPUT_PATH + "Session.json";
std::string SETUP_PATH = OUTPUT_PATH + "Setup.json";
std::string STATUS_PATH = OUTPUT_PATH + "Status.json";
std::string TELEMETRY_PATH = OUTPUT_PATH + "Telemetry.json";

std::vector<std::string> ALL_PATHS = {
    DATA_PATH,
    CLASSIFICATION_PATH,
    DAMAGE_PATH,
    EVENT_PATH,
    HEADER_PATH,
    HISTORY_PATH,
    LAP_PATH,
    LOBBY_PATH,
    MOTION_PATH,
    PARTICIPANT_PATH,
    SESSION_PATH,
    SETUP_PATH,
    STATUS_PATH,
    TELEMETRY_PATH
};

// PacketHeader packet_id
enum packetId : int {
    PACKET_ID_MOTION = 0,
    PACKET_ID_SESSION = 1,
    PACKET_ID_LAP_DATA = 2,
    PACKET_ID_EVENT = 3,
    PACKET_ID_PARTICIPANTS = 4,
    PACKET_ID_CAR_SETUPS = 5,
    PACKET_ID_CAR_TELEMETRY = 6,
    PACKET_ID_CAR_STATUS = 7,
    PACKET_ID_FINAL_CLASSIFICATION = 8,
    PACKET_ID_LOBBY_INFO = 9,
    PACKET_ID_CAR_DAMAGE = 10,
    PACKET_ID_SESSION_HISTORY = 11
};

static const char* const Packet_ID_name[] = {
    "Motion",        "Session",      "Lap Data",
    "Event",         "Participants", "Car Setup",
    "Car Telemetry", "Car Status",   "Final Classification",
    "Lobby Info"};

static const char* const TyrePosition[] = {"RearLeft", "RearRight", "FrontLeft",
                                           "FrontRight"};

// MarshalZone zoneFlag
enum MarshalZoneFlagId : int {
    MARHSAL_INVALID = -1,
    MARSHAL_NONE = 0,
    GREEN = 1,
    BLUE = 2,
    YELLOW = 3,
    RED = 4
};

static const char* const Marshal_Zone_Flag[] = {
    "Invalid/Unknown", "None", "Green", "Blue", "Yellow", "Red"};

// PacketSession sessionType
enum SessionTypeId : int {
    SESSION_UNKNOWN = 0,
    P1 = 1,
    P2 = 2,
    P3 = 3,
    SHORT_P = 4,
    Q1 = 5,
    Q2 = 6,
    Q3 = 7,
    SHORT_Q = 8,
    OSQ = 9,
    R = 10,
    R2 = 11,
    R3 = 12,
    TIME_TRIAL = 12
};

static const char* const Session_Type[] = {
    "Unknown", "FP1",     "FP2", "FP3", "Short_FP", "Q1", "Q2",
    "Q3",      "Short_Q", "OSQ", "R",   "R2",       "R3", "Time_Trial"};

enum WeatherId : int {
    CLEAR = 0,
    LIGHT_CLOUD = 1,
    OVERCAST = 2,
    LIGHT_RAIN = 3,
    HEAVY_RAIN = 4,
    STORM = 5
};

static const char* const Weather_Type[] = {
    "Clear", "Light Cloud", "Overcast", "Light Rain", "Heavy Rain", "Storm"};

enum TrackId : int {
    TRACK_UNKNOWN = -1,
    MELBOURNE = 0,
    PAUL_RICHARD = 1,
    SHANGHAI = 2,
    SAKHIR = 3,
    CATALUNYA = 4,
    MONACO = 5,
    MONTREAL = 6,
    SILVERSTONE = 7,
    HOCKENHEIM = 8,
    HUNGARORING = 9,
    SPA = 10,
    MONZA = 11,
    SINGAPORE = 12,
    SUZUKA = 13,
    ABU_DHABI = 14,
    TEXAS = 15,
    BRAZIL = 16,
    AUSTRIA = 17,
    SOCHI = 18,
    MEXICO = 19,
    BAKU = 20,
    SAKHIR_SHORT = 21,
    SILVERSTONE_SHORT = 22,
    TEXAS_SHORT = 23,
    SUZUKA_SHORT = 24,
    HANOI = 25,
    ZANDVOORT = 26,
    IMOLA = 27,
    PORTIMAO = 28,
    JEDDAH = 29,
    MIAMI = 30
};

static const char* const Track[] = {"Melbourne",
                                    "Paul Richard",
                                    "Shanghai",
                                    "Sakhir",
                                    "Catalunya",
                                    "Monaco",
                                    "Montreal",
                                    "Silverstone",
                                    "Hockenheim",
                                    "Hungaroring",
                                    "Spa",
                                    "Monza",
                                    "Singapore",
                                    "Suzuka",
                                    "Abu Dhabi",
                                    "Texas",
                                    "Brazil",
                                    "Austria",
                                    "Sochi",
                                    "Mexico",
                                    "Baku",
                                    "Short Sakhir",
                                    "Short Silverstone",
                                    "Short Texas",
                                    "Short Suzuka",
                                    "Hanoi",
                                    "Zandvoort",
                                    "Imola",
                                    "Portimao",
                                    "Jeddah",
                                    "Miami",
                                    "Unknown"};

enum FormulaId : int { F1_MODERN = 0, F1_CLASSIC = 1, F2 = 2, F1_GENERIC = 3 };

static const char* const Formula[] = {"F1 Modern", "F1 Classic", "F2",
                                      "F1 Generic"};

enum SafetyCarId : int {
    NO_SAFETY_CAR = 0,
    FULL_SAFETY_CAR = 1,
    VIRTUAL_SAFETY_CAR = 2
};

static const char* const SafetyCar[] = {"No Safety Car", "Full Safety Car",
                                        "Virtual Safety Car"};

enum PitStatusId : int { PIT_NONE = 0, PITTING = 1, IN_PIT_AREA = 2 };

static const char* const PitStatus[] = {"None", "Pitting", "In Pit Area"};

enum SectorId : int { SECTOR_1 = 0, SECTOR_2 = 1, SECTOR_3 = 2 };

static const char* const Sector[] = {"Sector 1", "Sector 2", "Sector 3"};

enum DriverStatusId : int {
    IN_GARAGE = 0,
    FLYING_LAP = 1,
    IN_LAP = 2,
    OUT_LAP = 3,
    ON_TRACK = 4
};

static const char* const DriverStatus[] = {"In Garage", "Flying Lap", "In Lap",
                                           "Out Lap", "On Track"};

enum ResultStatusId : int {
    RESULT_INVALID = 0,
    INACTIVE = 1,
    ACTIVE = 2,
    FINISHED = 3,
    DIQUALIFIED = 4,
    NOT_CLASSIFIED = 5,
    RETIRED = 6
};

static const char* const ResultStatus[] = {
    "Invalid",      "Inactive",       "Active", "Finished",
    "Disqualified", "Not Classified", "Retired"};

enum TeamId : int {
    MERCEDES = 0,
    FERRARI = 1,
    RED_BULL_RACING = 2,
    WILLIAMS = 3,
    RACING_POINT = 4,
    RENAULT = 5,
    ALPHA_TAYURI = 6,
    HAAS = 7,
    MCLAREN = 8,
    ALFA_ROMEO = 9,
    MCLAREN_1988 = 10,
    MCLAREN_1991 = 11,
    WILLIAMS_1992 = 12,
    FERRARI_1995 = 13,
    WILLIAMS_1996 = 14,
    MCLAREN_1998 = 15,
    FERRARI_2002 = 16,
    FERRARI_2004 = 17,
    RENAULT_2006 = 18,
    FERRARI_2007 = 19,
    MCLAREN_2008 = 20,
    RED_BULL_2010 = 21,
    FERRARI_1976 = 22,
    ART_GRAND_PRIX = 23,
    CAMPOS_VEXATEC_RACING = 24,
    CARLIN = 25,
    CHAROUZ_RACING_SYSTEM = 26,
    DAMS = 27,
    RUSSIAN_TIME = 28,
    MP_MOTORSPORT = 29,
    PERTAMINA = 30,
    MCLAREN_1990 = 31,
    TRIDENT = 32,
    BWT_ARDEN = 33,
    MCLAREN_1976 = 34,
    LOTUS_1972 = 35,
    FERRARI_1979 = 36,
    MCLAREN_1982 = 37,
    WILLIAMS_2003 = 38,
    BRAWN_2009 = 39,
    LOTUS_1978 = 40,
    F1_GENERIC_CAR = 41,
    ART_GP_19 = 42,
    CAMPOS_19 = 43,
    CARLIN_19 = 44,
    SAUBER_JUNIOR_CHAROUZ_19 = 45,
    DAMS_19 = 46,
    UNI_VIRTUOSI_19 = 47,
    MP_MOTORSPORT_19 = 48,
    PREMA_19 = 49,
    TRIDENT_19 = 50,
    ARDEN_19 = 51,
    BENETTON_1994 = 53,
    BENETTON_1995 = 54,
    FERRARI_2000 = 55,
    JORDAN_1991 = 56,
    MY_TEAM = 255
};

static const char* const Teams[] = {"Mercedes",
                                    "Ferrari",
                                    "Red Bull Racing",
                                    "Williams",
                                    "Racing Point",
                                    "Renault",
                                    "Alpha-Tauri",
                                    "Haas",
                                    "McLaren",
                                    "Alfa Romeo",
                                    "McLaren 1988",
                                    "McLaren 1991",
                                    "Williams 1992",
                                    "Ferrari 1995",
                                    "Williams 1996",
                                    "McLaren 1998",
                                    "Ferrari 2002",
                                    "Ferrari 2004",
                                    "Renault 2006",
                                    "Ferrari 2007",
                                    "McLaren 2008",
                                    "Red Bull 2010",
                                    "Ferrari 1976",
                                    "Art Grand Prix",
                                    "Campos Vexatec Racing",
                                    "Carlin",
                                    "Charouz Racing System",
                                    "Dams",
                                    "Russian Time",
                                    "MP Motorsport",
                                    "Pertamina",
                                    "McLaren 1990",
                                    "Trident",
                                    "BWT Arden",
                                    "McLaren 1976",
                                    "Lotus 1972",
                                    "Ferrari 1979",
                                    "McLaren 1982",
                                    "Williams 2003",
                                    "Brawn 2009",
                                    "Lotus 1978",
                                    "F1 Generic Car",
                                    "Art GP 19",
                                    "Campos 19",
                                    "Carlin 19",
                                    "Sauber Junior Charouz 19",
                                    "Dams 19",
                                    "Uni VIRTUOSI 19",
                                    "MP Motorsport 19",
                                    "Premia 19",
                                    "Trident 19",
                                    "Arden 19",
                                    "NULL",
                                    "Benetton 1994",
                                    "Benetton 1995",
                                    "Ferrari 2000",
                                    "Jordan 1991",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "NULL",
                                    "My Team"};

enum DriverId : int {
    CARLOS_SAINZ = 0,
    DANIIL_KVYAT = 1,
    DANIEL_RICCIARDO = 2,
    KIMI_RAIKKONEN = 6,
    LEWIS_HAMILTON = 7,
    MAX_VERSTAPPEN = 9,
    NICO_HULKENBERG = 10,
    KEVIN_MAGNUSSEN = 11,
    ROMAIN_GROSJEAN = 12,
    SEBASTIAN_VETTEL = 13,
    SERGIO_PEREZ = 14,
    VALTERRI_BOTTAS = 15,
    ESTEBAN_OCON = 16,
    LANCE_STROLL = 19,
    AARON_BARNES = 20,
    MARTIN_GILES = 21,
    ALEX_MURRAY = 22,
    LUCAS_ROTH = 23,
    IGOR_CORREIA = 24,
    SOPHIE_LEVASSEUR = 25,
    JONAS_SCHIFFER = 26,
    ALAIN_FOREST = 27,
    JAY_LETOURNEAU = 28,
    ESTO_SAARI = 29,
    YASAR_ATIYEH = 30,
    CALLISTO_CALABRESI = 31,
    NAOTA_IZUM = 32,
    HOWARD_CLARKE = 33,
    WILHEIM_KAUFMANN = 34,
    MARIE_LAURSEN = 35,
    FLAVIO_NIEVES = 36,
    PETER_BELOUSOV = 37,
    KLIMEK_MICHALSKI = 38,
    SANTIAGO_MORENO = 39,
    BENJAMIN_COPPENS = 40,
    NOAH_VISSER = 41,
    GERT_WALDMULLER = 42,
    JULIAN_QUESADA = 43,
    DANIEL_JONES = 44,
    ARTEM_MARKELOV = 45,
    TADASUKE_MAKINO = 46,
    SEAN_GELAEL = 47,
    NYCK_DE_VRIES = 48,
    JACK_AITKEN = 49,
    GEORGE_RUSSEL = 50,
    MAXIMILIAN_GUNTHER = 51,
    NIREI_FUKUZUMI = 52,
    LUCA_GHIOTTO = 53,
    LANDO_NORRIS = 54,
    SERGIO_SETTE_CAMARA = 55,
    LOUIS_DELETRAZ = 56,
    ANTONIO_FUOCO = 57,
    CHARLES_LECLERC = 58,
    PIERRE_GASLY = 59,
    ALEXANDER_ALBON = 62,
    NICHOLAS_LATIFI = 63,
    DORIAN_BOCCOLACCI = 64,
    NIKO_KARI = 65,
    ROBERTO_MERHI = 66,
    ARJUN_MAINI = 67,
    ALESSIO_LORANDI = 68,
    RUBEN_MEJIER = 69,
    RASHID_NAIR = 70,
    JACK_TREMBLAY = 71,
    ANTONIO_GIOVINAZZI = 74,
    ROBERT_KUBICA = 75,
    NOBUHARU_MATSUSHITA = 78,
    NIKITA_MAZEPIN = 79,
    GUANYA_ZHOU = 80,
    MICK_SCHUMACHER = 81,
    CALLUM_ILOTT = 82,
    JUAN_MANUEL_CORREA = 83,
    JORDAN_KING = 84,
    MEHAVEER_RAGHUNATHAN = 85,
    TATIANA_CALDERON = 86,
    ANTOINE_HUBERT = 87,
    GIULIANO_ALESI = 88,
    RALPH_BOSCHUNG = 89
};

static const char* const Drivers[] = {"Carlos Sainz",
                                      "Daniil Kvyar",
                                      "Daniel Ricciardo",
                                      "NULL",
                                      "NULL",
                                      "NULL",
                                      "Kimi Raikkonen",
                                      "Lewis Hamilton",
                                      "NULL",
                                      "Max Verstappen",
                                      "Nico Hulkenberg",
                                      "Kevin Magnussen",
                                      "Romain Grosjean",
                                      "Sebastian Vettel",
                                      "Sergio Perez",
                                      "Valtteri Bottas",
                                      "NULL",
                                      "Esteban Ocon",
                                      "NULL",
                                      "Lance Stroll",
                                      "Arron Barnes",
                                      "Martin Giles",
                                      "Alex Murray",
                                      "Lucas Roth",
                                      "Igor Correia",
                                      "Sophie Levasseur",
                                      "Jonas Schiffer",
                                      "Alain Forest",
                                      "Jay Letourneau",
                                      "Esto Saari",
                                      "Yasar Atiyeh",
                                      "Callisto Calabresi",
                                      "Naota Izum",
                                      "Howard Clarke",
                                      "Wilheim Kaufmann",
                                      "Marie Laursen",
                                      "Flavio Nieves",
                                      "Peter Belousov",
                                      "Klimek Michalski",
                                      "Santiago Moreno",
                                      "Benjamin Coppens",
                                      "Noah Visser",
                                      "Gert Waldmuller",
                                      "Julian Quesada",
                                      "Daniel Jones",
                                      "Artem Markelov",
                                      "Tadasuke Makino",
                                      "Sean Gelaels",
                                      "Nyck de Vries",
                                      "Jack Aitken",
                                      "George Russell",
                                      "Maximilian Gunther",
                                      "Nirei Fukuzumi",
                                      "Luca Ghiotto",
                                      "Landon Norris",
                                      "Sergio Setticamara",
                                      "Louis Deletraz",
                                      "Antonio Fuoco",
                                      "Charles Leclerc",
                                      "Pierre Gasly",
                                      "NULL",
                                      "NULL",
                                      "Alexander Albon",
                                      "Nicholas Latifi",
                                      "Dorian Boccocci",
                                      "Niko Kari",
                                      "Roberto Merhi",
                                      "Arjun Maini",
                                      "Alessio Lorandi",
                                      "Ruben Mejier",
                                      "Rashid Nair",
                                      "Jack Tremblay",
                                      "NULL",
                                      "NULL",
                                      "Antonio Giovinazzi",
                                      "Robert Kubica",
                                      "NULL",
                                      "NULL",
                                      "Nobuharu Matsushita",
                                      "Nikita Mazepin",
                                      "Guanya Zhou",
                                      "Mick Schumacher",
                                      "Callum Illiot",
                                      "Juan Manuel Correa",
                                      "Jordan King",
                                      "Mehaveer Raghunathan",
                                      "Tatiana Calderon",
                                      "Antoine Hubert",
                                      "Giuliano Alesi",
                                      "Ralph Boschung"};

enum NationalityID : int {
    AMERICAN = 1,
    ARGENTINEAN = 2,
    AUSTRALIAN = 3,
    AUSTRIAN = 4,
    AZERBAIJANI = 5,
    BAHRAINI = 6,
    BELGIAN = 7,
    BOLIVIAN = 8,
    BRAZILIAN = 9,
    BRITISH = 10,
    BULGARIAN = 11,
    CAMEROONIAN = 12,
    CANADIAN = 13,
    CHILEAN = 14,
    CHINESE = 15,
    COLOMBIAN = 16,
    COSTA_RICAN = 17,
    CROATIAN = 18,
    CYPRIOT = 19,
    CZECH = 20,
    DANISH = 21,
    DUTCH = 22,
    ECUADORIAN = 23,
    ENGLISH = 24,
    EMIRIAN = 25,
    ESTONIAN = 26,
    FINNISH = 27,
    FRENCH = 28,
    GERMAN = 29,
    GHANAIAN = 30,
    GREEK = 31,
    GUATEMALAN = 32,
    HONDURAN = 33,
    HONG_KONGER = 34,
    HUNGARIAN = 35,
    ICELANDER = 36,
    INDIAN = 37,
    INDONESIAN = 38,
    IRISH = 39,
    ISRAELI = 40,
    ITALIAN = 41,
    JAMAICAN = 42,
    JAPANESE = 43,
    JORDANIAN = 44,
    KUWAITI = 45,
    LATVIAN = 46,
    LEBANESE = 47,
    LITHUANIAN = 48,
    LUXEMBOURGER = 49,
    MALAYSIAN = 50,
    MALTESE = 51,
    MEXICAN = 52,
    MONEGASQUE = 53,
    NEW_ZEALANDER = 54,
    NICARAGUAN = 55,
    NORTH_KOREAN = 56,
    NORTHERN_IRISH = 57,
    NORWEGIAN = 58,
    OMANI = 59,
    PAKISTANI = 60,
    PANAMANIAN = 61,
    PARAGUAYAN = 62,
    PERUVIAN = 63,
    POLISH = 64,
    PORTUGUESE = 65,
    QATARI = 66,
    ROMANIAN = 67,
    RUSSIAN = 68,
    SALVADORAN = 69,
    SAUDI = 70,
    SCOTTISH = 71,
    SERBIAN = 72,
    SINGAPOREAN = 73,
    SLOVAKIAN = 74,
    SLOVENIAN = 75,
    SOUTH_KOREAN = 76,
    SOUTH_AFRICAN = 77,
    SPANISH = 78,
    SWEDISH = 79,
    SWISS = 80,
    THAI = 81,
    TURKISH = 82,
    URUGUAYAN = 83,
    UKRAINIAN = 84,
    VENEZUELAN = 85,
    WELSH = 86,
    BARBADIAN = 87,
    VIETNAMESE = 88
};

static const char* const Nationalities[] = {
    "NULL",         "American",       "Argentinean",   "Australian",
    "Austrian",     "Azerbaijani",    "Bahraini",      "Belgian",
    "Bolivian",     "Brazilian",      "British",       "Bulgarian",
    "Cameroonian",  "Canadian",       "Chilean",       "Chinese",
    "Colombian",    "Costa Rican",    "Croatian",      "Cypriot",
    "Czech",        "Danish",         "Dutch",         "Ecuadorean",
    "English",      "Emirian",        "Estonian",      "Finnish",
    "French",       "German",         "Ghanaian",      "Greek",
    "Guatemalan",   "Honduran",       "Hong Konger",   "Hungarian",
    "Icelander",    "Indian",         "Indonesian",    "Irish",
    "Israeli",      "Italian",        "Jamaican",      "Japanese",
    "Jordanian",    "Kuwaiti",        "Latvian",       "Lebanese",
    "Lithuanian",   "Luxembourger",   "Malaysian",     "Maltese",
    "Mexican",      "Monegasque",     "New Zealander", "Nicaraguan",
    "North Korean", "Northern Irish", "Norwegian",     "Omani",
    "Pakistani",    "Panamanian",     "Paraguayan",    "Peruvian",
    "Polish",       "Portuguese",     "Qatari",        "Romanian",
    "Russian",      "Salvadoran",     "Saudi",         "Scottish",
    "Serbian",      "Singaporean",    "Slovakian",     "Slovenian",
    "South Korean", "South African",  "Spanish",       "Swedish",
    "Swiss",        "Thai",           "Turkish",       "Uruguayan",
    "Ukrainian",    "Venezuelan",     "Welsh",         "Barbadian",
    "Vietnamese"};

enum SurfaceId : int {
    TARMAC = 0,
    RUMBLE_STRIPS = 1,
    CONCRETE = 2,
    ROCK = 3,
    GRAVEL = 4,
    MUD = 5,
    SAND = 6,
    GRASS = 7,
    WATER = 8,
    COBBLESTONE = 9,
    METAL = 10,
    RIDGED = 11
};

static const char* const Surfaces[] = {
    "Tarmac", "Rumble Strips", "Concrete", "Rock",        "Gravel", "Mud",
    "Sand",   "Grass",         "Water",    "Cobblestone", "Metal",  "Ridged"};

enum MFDId : int {
    MFD_CLOSED = 255,
    CAR_SETUP = 0,
    PITS = 1,
    DAMAGE = 2,
    ENGINE = 3,
    TEMPERATURE = 4
};

static const char* const MFD[] = {
    "Car Setup", "Pits", "Damage", "Engine",    "Temperature", "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "NULL",      "NULL",        "NULL", "NULL",
    "NULL",      "NULL", "NULL",   "MFD Closed"};

/*enum BitFlagId: int{
    CROSS_A = 0001,
    TRIANGLE_Y = 0002,
    CIRCLE_B = 0004,
    SQUARE_X = 0008,
    D_PAD_LEFT = 0010,
    D_PAD_RIGHT = 0020,
    D_PAD_UP = 0040,
    D_PAD_DOWN = 0080,
    OPTIONS_MENU = 0100,
    L1_LB = 0200,
    R1_RB = 0400,
    L2_LT = 0800,
    R2_RT = 1000,
    L3_LS = 2000,
    R3_RS = 4000,
};*/

// INCOMPLETE
static const char* const BitFlag[] = {
    "Cross - A",   "Triangle - Y", "Circle - B", "Square - X",    "D-Pad Left",
    "D-Pad Right", "D-Pad Up",     "D-Pad Down", "Options - Menu"};

static const char* const Wheels[] = {"RearLeft", "RearRight", "FrontLeft",
                                     "FrontRight"};

static const char* const TyreCompound[] = {
    "NULL",        // 0
    "NULL",        // 1
    "NULL",        // 2
    "NULL",        // 3
    "NULL",        // 4
    "NULL",        // 5
    "NULL",        // 6
    "Inter",       // 7
    "Wet",         // 8
    "Dry",         // 9
    "Wet",         // 10
    "Super Soft",  // 11
    "Soft",        // 12
    "Medium",      // 13
    "Hard",        // 14
    "Wet",         // 15
    "C5",          // 16
    "C4",          // 17
    "C3",          // 18
    "C2",          // 19
    "C1"           // 20

};

static const char* const VisualTyreCompound[] = {
    "NULL",        // 0
    "NULL",        // 1
    "NULL",        // 2
    "NULL",        // 3
    "NULL",        // 4
    "NULL",        // 5
    "NULL",        // 6
    "Inter",       // 7
    "Wet",         // 8
    "Dry",         // 9
    "Wet",         // 10
    "Super Soft",  // 11
    "Soft",        // 12
    "Medium",      // 13
    "Hard",        // 14
    "Wet",         // 15
    "Soft",        // 16
    "Medium",      // 17
    "Hard",        // 18
    "C2",          // 19
    "C1"           // 20
};

void writeJsonDataToFile(std::string filename, Json::Value data, uint32 frame) {
    std::ofstream file;
    file.open(filename, std::ios::app);
    if (frame == 0) {
        file << data;
    } else {
        file << "," << data;
    }
    file.close();
}

#endif
