var Net = new ActiveXObject("Net.DotNet");

Net.Import("System");
Net.Import("System.Net");

var webClient = new Net.Runtime.System.Net.WebClient();
webClient.Encoding = Net.Runtime.System.Text.Encoding.UTF8;

var uri = new Net.Runtime.System.Uri("http://www.heise.de/");
var result = webClient.DownloadString(uri);

var doc = moe.Documents.New();
doc.Object.Properties.Encoding = moe.UTF8; // UTF-8
doc.Object.Text = result;

Net.Exit();