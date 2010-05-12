package mol.excel  ;

import com4j.*;

@IID("{0002085F-0001-0000-C000-000000000046}")
public interface IToolbarButtons extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.ToolbarButton add(
        @MarshalAs(NativeType.VARIANT) java.lang.Object button,
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object onAction,
        @MarshalAs(NativeType.VARIANT) java.lang.Object pushed,
        @MarshalAs(NativeType.VARIANT) java.lang.Object enabled,
        @MarshalAs(NativeType.VARIANT) java.lang.Object statusBar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpContextID);

    @VTID(11)
    int count();

    @VTID(12)
    mol.excel.ToolbarButton item(
        int index);

    @VTID(13)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(14)
    @DefaultMethod
    mol.excel.ToolbarButton _Default(
        int index);

}
