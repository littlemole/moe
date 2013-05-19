set dot = NET()

set Drawing = dot.Import("System.Drawing")
set Forms = dot.Import("System.Windows.Forms")


set button1 = Forms.Button()

Sub button1_Click(s,e) 
	
   Forms.Application.Exit()
end Sub


set button1.Location = Drawing.Point(46, 51)
set button1.Size = Drawing.Size(180, 104)
button1.Text = "button1"

'dot.Connect GetRef("button1_Click"),"Click",button1
button1.On "Click", GetRef("button1_Click")

'x = Dialogs.MsgBox("hu","ha",0)

set f = Forms.Form()
f.SuspendLayout()


set f.ClientSize = Drawing.Size(284, 262)
f.Controls.Add(button1)
f.Text = "Test Form1"

f.ResumeLayout(false)
f.Show()
f.Activate()

dot.Runtime.System.Windows.Forms.Application.Run(f)

