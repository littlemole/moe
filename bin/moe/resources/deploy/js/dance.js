function resize(doc)
{
	var w = doc.View.Width * 0.8;
	var h = doc.View.Height * 0.8;

	doc.View.Width = w;
	doc.View.Height = h;

	doc.View.Left = doc.View.Left + (w*0.1);
	doc.View.Top = doc.View.Top + (h*0.1);
}


function circle(obj)
{

	var x = Math.cos(obj.c) * 30 + obj.x;
	var y = Math.sin(obj.c) * 30 + obj.y;

	obj.doc.View.Left = x;
	obj.doc.View.Top = y;

	obj.c = obj.c + 0.1;
	if(obj.c>16) 
		Quit();
	else
		setTimeout( function() { circle(obj); }, 5 );
}

moe.View.Tile();
setTimeout( function() {

	for( i = 0; i < moe.Documents.Count; i++)
	{
		var doc = moe.Documents.Item(i);
		resize(doc);	
	}
	for( i = 0; i < moe.Documents.Count; i++)
	{
		var doc = moe.Documents.Item(i);
		circle({ doc:doc, x:doc.View.Left, y:doc.View.Top, c:0.0});
	}
	//Quit();
	},200
);

Wait();
