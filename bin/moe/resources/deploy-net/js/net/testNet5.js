var Net = new ActiveXObject("Net.DotNet");

Net.Import("System.Net");
Net.Import("System");

var webClient = Net("System.Net.WebClient").New();
webClient.Encoding = Net("System.Text.Encoding").UTF8;

var uri = Net("System.Uri").New("http://www.heise.de/");
var result = webClient.DownloadString(uri);

var doc = moe.Documents.New();
doc.Object.Properties.Encoding = moe.UTF8; // UTF-8
doc.Object.Text = result;

Net.Exit();