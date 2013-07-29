var path = new ActiveXObject("IO.Path");
var diff = new ActiveXObject("IO.UniDiff");

// prepare path source (original)
var source = ActiveDoc.Object.Text.Value;

// prepare path
var filename = Dialogs.ChooseFile();

var patch = "";
var file = path.OpenFile(filename);
if ( file ) {
  patch = file.ReadText();
  file.Close();
}

// do the diff -u
var patched = diff.Patch(source,patch);

// show results in new Document
var d = Documents.New();
d.Object.Text.SetText(patched);

