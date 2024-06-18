var id = 'Enter sheet ID';

function doGet(e) {

  if (e.parameter == undefined) {
    result = 'Parameter undefined';
  }else {
    var sheet = SpreadsheetApp.openById(id).getActiveSheet();
    var newRow = sheet.getLastRow() + 1; // Type on next line
    var rowData = [];
    rowData[0] = new Date(); //TimeStamp

    for (var param in e.parameter) {
      var value = e.parameter[param];
      rowData[parseInt(param)] = value;
    }

    var newRange = sheet.getRange(newRow, 1, 1, rowData.length);
    newRange.setValues([rowData]);
    var result = 'Ok'
  }
  return ContentService.createTextOutput(result);
}