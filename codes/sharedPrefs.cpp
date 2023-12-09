class SharedPrefs {
  static SharedPreferences? _sharedPrefs;

  static Future<void> initialize() async {
    _sharedPrefs ??= await SharedPreferences.getInstance();
  }

  static Future<void> saveTVModels(List<TVModel> tvModels) async {
    await initialize();
    List<Map<String, dynamic>> jasonTVModels =
        tvModels.map((tvModel) => tvModel.toJson()).toList();
    await _sharedPrefs!.setString('tvModels', json.encode(jasonTVModels));
  }

  static Future<List<TVModel>> getTVModels() async {
    await initialize();
    final jsonString = _sharedPrefs!.getString('tvModels');
    if (jsonString == null) {
      return [];
    }
    List<dynamic> jasonTVModels = json.decode(jsonString);
    return jasonTVModels.map((json) => TVModel.fromJson(json)).toList();
  }