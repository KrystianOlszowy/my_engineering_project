Map<String, dynamic> toJson() {
    return {
      'id': _id,
      'irCode': _irCode,
    };
  }

  Button.fromJson(Map<String, dynamic> json)
      : _id = json['id'] as int,
        _irCode = json['irCode'] as int;