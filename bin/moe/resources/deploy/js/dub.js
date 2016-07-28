var fp = moe.Documents.ActiveDoc.FilePath;
var ioPath = Script.CreateObject("IO.Path");
var pp = Script.CreateObject("PipedProcess.PipedProcessControl");
var p = ioPath.Path(fp);

function pathHasDub(path,dubfile) {

   var tmp = path + "\\" + dubfile;

   if (ioPath.Exists(tmp)) {
	  return path;
   }
   return null;
}

function findDub(path) {
	
	var tmp = pathHasDub(path,"dub.sdl");
	if(!tmp) {
		tmp = pathHasDub(path,"dub.json");
	}
	if(tmp) {
		return tmp;
	}

	var p = ioPath.ParentDir(path);
	if(!p)
		return null;

	return findDub(p);
}

function complete() {

	var txt = "";
	while( !(pp.Eof) ) {
		txt += pp.ReadLine() + "\r\n";
	}

	moe.Documents.ActiveDoc.Object.Annotation.setText(0,txt);
	pp.Close();
	Quit();
}

var tmp  = findDub(p);

if(tmp) {

	//Script.System("dub.exe --root \"" + tmp + "\"");
	pp.Async = true;
	pp.onComplete = complete;

	pp.Create("dub.exe test --root \"" + tmp + "\"");
	pp.CloseOut(); 

	Wait(0);
}

