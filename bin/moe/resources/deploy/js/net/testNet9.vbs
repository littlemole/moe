
set dot = NET()

Class TestPrototype
   Public x
   Public Value
   Public Value2
End Class

set prototype = new TestPrototype

set prototype.Value = dot.Runtime.System.String
set prototype.Value2 = dot.Runtime.System.Int32
set prototype.x = dot.Runtime.System.Int32

dot.Runtime.My.Test = prototype


set test = dot.Runtime.My.Test() 

test.x = 42
test.Value = "hu"
test.Value2 = 123

r = Dialogs.MsgBox( test.Value, test.Value2,0)
r = Dialogs.MsgBox( test.x, test.x,0)


dot.Exit()
