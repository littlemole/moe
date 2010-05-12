package mol.excel  ;

import com4j.*;

@IID("{00020867-0001-0000-C000-000000000046}")
public interface IMenuItems extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.excel.MenuItem add(
        java.lang.String caption,
        @MarshalAs(NativeType.VARIANT) java.lang.Object onAction,
        @MarshalAs(NativeType.VARIANT) java.lang.Object shortcutKey,
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object restore,
        @MarshalAs(NativeType.VARIANT) java.lang.Object statusBar,
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpFile,
        @MarshalAs(NativeType.VARIANT) java.lang.Object helpContextID);

    @VTID(11)
    mol.excel.Menu addMenu(
        java.lang.String caption,
        @MarshalAs(NativeType.VARIANT) java.lang.Object before,
        @MarshalAs(NativeType.VARIANT) java.lang.Object restore);

    @VTID(12)
    int count();

    @VTID(13)
    @DefaultMethod
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject _Default(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(15)
    java.util.Iterator<Com4jObject> iterator();

}
