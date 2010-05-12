package mol.excel  ;

import com4j.*;

@IID("{00020845-0001-0000-C000-000000000046}")
public interface IWorksheetFunction extends Com4jObject {
    @VTID(7)
    mol.excel._Application application();

    @VTID(8)
    mol.excel.XlCreator creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object _WSFunction(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(11)
    double count(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(12)
    boolean isNA(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(13)
    boolean isError(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(14)
    double sum(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(15)
    double average(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(16)
    double min(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(17)
    double max(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(18)
    double npv(
        double arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(19)
    double stDev(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(20)
    java.lang.String dollar(
        double arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(21)
    java.lang.String fixed(
        double arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(22)
    double pi();

    @VTID(23)
    double ln(
        double arg1);

    @VTID(24)
    double log10(
        double arg1);

    @VTID(25)
    double round(
        double arg1,
        double arg2);

    @VTID(26)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object lookup(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(27)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object index(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        double arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(28)
    java.lang.String rept(
        java.lang.String arg1,
        double arg2);

    @VTID(29)
    boolean and(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(30)
    boolean or(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(31)
    double dCount(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(32)
    double dSum(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(33)
    double dAverage(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(34)
    double dMin(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(35)
    double dMax(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(36)
    double dStDev(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(37)
    double var(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(38)
    double dVar(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(39)
    java.lang.String text(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        java.lang.String arg2);

    @VTID(40)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object linEst(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(41)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object trend(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(42)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object logEst(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(43)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object growth(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(44)
    double pv(
        double arg1,
        double arg2,
        double arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(45)
    double fv(
        double arg1,
        double arg2,
        double arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(46)
    double nPer(
        double arg1,
        double arg2,
        double arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(47)
    double pmt(
        double arg1,
        double arg2,
        double arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(48)
    double rate(
        double arg1,
        double arg2,
        double arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6);

    @VTID(49)
    double mIrr(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        double arg2,
        double arg3);

    @VTID(50)
    double irr(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(51)
    double match(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(52)
    double weekday(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(53)
    double search(
        java.lang.String arg1,
        java.lang.String arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(54)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object transpose(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(55)
    double atan2(
        double arg1,
        double arg2);

    @VTID(56)
    double asin(
        double arg1);

    @VTID(57)
    double acos(
        double arg1);

    @VTID(58)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object choose(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(59)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object hLookup(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(60)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object vLookup(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(61)
    double log(
        double arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(62)
    java.lang.String proper(
        java.lang.String arg1);

    @VTID(63)
    java.lang.String trim(
        java.lang.String arg1);

    @VTID(64)
    java.lang.String replace(
        java.lang.String arg1,
        double arg2,
        double arg3,
        java.lang.String arg4);

    @VTID(65)
    java.lang.String substitute(
        java.lang.String arg1,
        java.lang.String arg2,
        java.lang.String arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(66)
    double find(
        java.lang.String arg1,
        java.lang.String arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(67)
    boolean isErr(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(68)
    boolean isText(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(69)
    boolean isNumber(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(70)
    double sln(
        double arg1,
        double arg2,
        double arg3);

    @VTID(71)
    double syd(
        double arg1,
        double arg2,
        double arg3,
        double arg4);

    @VTID(72)
    double ddb(
        double arg1,
        double arg2,
        double arg3,
        double arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(73)
    java.lang.String clean(
        java.lang.String arg1);

    @VTID(74)
    double mDeterm(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(75)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object mInverse(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(76)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object mMult(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(77)
    double ipmt(
        double arg1,
        double arg2,
        double arg3,
        double arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6);

    @VTID(78)
    double ppmt(
        double arg1,
        double arg2,
        double arg3,
        double arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6);

    @VTID(79)
    double countA(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(80)
    double product(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(81)
    double fact(
        double arg1);

    @VTID(82)
    double dProduct(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(83)
    boolean isNonText(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(84)
    double stDevP(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(85)
    double varP(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(86)
    double dStDevP(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(87)
    double dVarP(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(88)
    boolean isLogical(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(89)
    double dCountA(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(90)
    java.lang.String usDollar(
        double arg1,
        double arg2);

    @VTID(91)
    double findB(
        java.lang.String arg1,
        java.lang.String arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(92)
    double searchB(
        java.lang.String arg1,
        java.lang.String arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(93)
    java.lang.String replaceB(
        java.lang.String arg1,
        double arg2,
        double arg3,
        java.lang.String arg4);

    @VTID(94)
    double roundUp(
        double arg1,
        double arg2);

    @VTID(95)
    double roundDown(
        double arg1,
        double arg2);

    @VTID(96)
    double rank(
        double arg1,
        mol.excel.Range arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(97)
    double days360(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(98)
    double vdb(
        double arg1,
        double arg2,
        double arg3,
        double arg4,
        double arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7);

    @VTID(99)
    double median(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(100)
    double sumProduct(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(101)
    double sinh(
        double arg1);

    @VTID(102)
    double cosh(
        double arg1);

    @VTID(103)
    double tanh(
        double arg1);

    @VTID(104)
    double asinh(
        double arg1);

    @VTID(105)
    double acosh(
        double arg1);

    @VTID(106)
    double atanh(
        double arg1);

    @VTID(107)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object dGet(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(108)
    double db(
        double arg1,
        double arg2,
        double arg3,
        double arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(109)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object frequency(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(110)
    double aveDev(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(111)
    double betaDist(
        double arg1,
        double arg2,
        double arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(112)
    double gammaLn(
        double arg1);

    @VTID(113)
    double betaInv(
        double arg1,
        double arg2,
        double arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(114)
    double binomDist(
        double arg1,
        double arg2,
        double arg3,
        boolean arg4);

    @VTID(115)
    double chiDist(
        double arg1,
        double arg2);

    @VTID(116)
    double chiInv(
        double arg1,
        double arg2);

    @VTID(117)
    double combin(
        double arg1,
        double arg2);

    @VTID(118)
    double confidence(
        double arg1,
        double arg2,
        double arg3);

    @VTID(119)
    double critBinom(
        double arg1,
        double arg2,
        double arg3);

    @VTID(120)
    double even(
        double arg1);

    @VTID(121)
    double exponDist(
        double arg1,
        double arg2,
        boolean arg3);

    @VTID(122)
    double fDist(
        double arg1,
        double arg2,
        double arg3);

    @VTID(123)
    double fInv(
        double arg1,
        double arg2,
        double arg3);

    @VTID(124)
    double fisher(
        double arg1);

    @VTID(125)
    double fisherInv(
        double arg1);

    @VTID(126)
    double floor(
        double arg1,
        double arg2);

    @VTID(127)
    double gammaDist(
        double arg1,
        double arg2,
        double arg3,
        boolean arg4);

    @VTID(128)
    double gammaInv(
        double arg1,
        double arg2,
        double arg3);

    @VTID(129)
    double ceiling(
        double arg1,
        double arg2);

    @VTID(130)
    double hypGeomDist(
        double arg1,
        double arg2,
        double arg3,
        double arg4);

    @VTID(131)
    double logNormDist(
        double arg1,
        double arg2,
        double arg3);

    @VTID(132)
    double logInv(
        double arg1,
        double arg2,
        double arg3);

    @VTID(133)
    double negBinomDist(
        double arg1,
        double arg2,
        double arg3);

    @VTID(134)
    double normDist(
        double arg1,
        double arg2,
        double arg3,
        boolean arg4);

    @VTID(135)
    double normSDist(
        double arg1);

    @VTID(136)
    double normInv(
        double arg1,
        double arg2,
        double arg3);

    @VTID(137)
    double normSInv(
        double arg1);

    @VTID(138)
    double standardize(
        double arg1,
        double arg2,
        double arg3);

    @VTID(139)
    double odd(
        double arg1);

    @VTID(140)
    double permut(
        double arg1,
        double arg2);

    @VTID(141)
    double poisson(
        double arg1,
        double arg2,
        boolean arg3);

    @VTID(142)
    double tDist(
        double arg1,
        double arg2,
        double arg3);

    @VTID(143)
    double weibull(
        double arg1,
        double arg2,
        double arg3,
        boolean arg4);

    @VTID(144)
    double sumXMY2(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(145)
    double sumX2MY2(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(146)
    double sumX2PY2(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(147)
    double chiTest(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(148)
    double correl(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(149)
    double covar(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(150)
    double forecast(
        double arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(151)
    double fTest(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(152)
    double intercept(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(153)
    double pearson(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(154)
    double rSq(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(155)
    double stEyx(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(156)
    double slope(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(157)
    double tTest(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        double arg3,
        double arg4);

    @VTID(158)
    double prob(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        double arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(159)
    double devSq(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(160)
    double geoMean(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(161)
    double harMean(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(162)
    double sumSq(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(163)
    double kurt(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(164)
    double skew(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(165)
    double zTest(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        double arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(166)
    double large(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        double arg2);

    @VTID(167)
    double small(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        double arg2);

    @VTID(168)
    double quartile(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        double arg2);

    @VTID(169)
    double percentile(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        double arg2);

    @VTID(170)
    double percentRank(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        double arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(171)
    double mode(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(172)
    double trimMean(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        double arg2);

    @VTID(173)
    double tInv(
        double arg1,
        double arg2);

    @VTID(174)
    double power(
        double arg1,
        double arg2);

    @VTID(175)
    double radians(
        double arg1);

    @VTID(176)
    double degrees(
        double arg1);

    @VTID(177)
    double subtotal(
        double arg1,
        mol.excel.Range arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(178)
    double sumIf(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(179)
    double countIf(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(180)
    double countBlank(
        mol.excel.Range arg1);

    @VTID(181)
    double ispmt(
        double arg1,
        double arg2,
        double arg3,
        double arg4);

    @VTID(182)
    java.lang.String roman(
        double arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(183)
    java.lang.String asc(
        java.lang.String arg1);

    @VTID(184)
    java.lang.String dbcs(
        java.lang.String arg1);

    @VTID(185)
    java.lang.String phonetic(
        mol.excel.Range arg1);

    @VTID(186)
    java.lang.String bahtText(
        double arg1);

    @VTID(187)
    java.lang.String thaiDayOfWeek(
        double arg1);

    @VTID(188)
    java.lang.String thaiDigit(
        java.lang.String arg1);

    @VTID(189)
    java.lang.String thaiMonthOfYear(
        double arg1);

    @VTID(190)
    java.lang.String thaiNumSound(
        double arg1);

    @VTID(191)
    java.lang.String thaiNumString(
        double arg1);

    @VTID(192)
    double thaiStringLength(
        java.lang.String arg1);

    @VTID(193)
    boolean isThaiDigit(
        java.lang.String arg1);

    @VTID(194)
    double roundBahtDown(
        double arg1);

    @VTID(195)
    double roundBahtUp(
        double arg1);

    @VTID(196)
    double thaiYear(
        double arg1);

    @VTID(197)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object rtd(
        @MarshalAs(NativeType.VARIANT) java.lang.Object progID,
        @MarshalAs(NativeType.VARIANT) java.lang.Object server,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object topic28);

    @VTID(198)
    java.lang.String hex2Bin(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(199)
    java.lang.String hex2Dec(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(200)
    java.lang.String hex2Oct(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(201)
    java.lang.String dec2Bin(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(202)
    java.lang.String dec2Hex(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(203)
    java.lang.String dec2Oct(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(204)
    java.lang.String oct2Bin(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(205)
    java.lang.String oct2Hex(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(206)
    java.lang.String oct2Dec(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(207)
    java.lang.String bin2Dec(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(208)
    java.lang.String bin2Oct(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(209)
    java.lang.String bin2Hex(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(210)
    java.lang.String imSub(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(211)
    java.lang.String imDiv(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(212)
    java.lang.String imPower(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(213)
    java.lang.String imAbs(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(214)
    java.lang.String imSqrt(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(215)
    java.lang.String imLn(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(216)
    java.lang.String imLog2(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(217)
    java.lang.String imLog10(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(218)
    java.lang.String imSin(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(219)
    java.lang.String imCos(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(220)
    java.lang.String imExp(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(221)
    java.lang.String imArgument(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(222)
    java.lang.String imConjugate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(223)
    double imaginary(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(224)
    double imReal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(225)
    java.lang.String complex(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(226)
    java.lang.String imSum(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(227)
    java.lang.String imProduct(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(228)
    double seriesSum(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(229)
    double factDouble(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(230)
    double sqrtPi(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(231)
    double quotient(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(232)
    double delta(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(233)
    double geStep(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(234)
    boolean isEven(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(235)
    boolean isOdd(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(236)
    double mRound(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(237)
    double erf(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(238)
    double erfC(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1);

    @VTID(239)
    double besselJ(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(240)
    double besselK(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(241)
    double besselY(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(242)
    double besselI(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(243)
    double xirr(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(244)
    double xnpv(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(245)
    double priceMat(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6);

    @VTID(246)
    double yieldMat(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6);

    @VTID(247)
    double intRate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(248)
    double received(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(249)
    double disc(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(250)
    double priceDisc(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(251)
    double yieldDisc(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(252)
    double tBillEq(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(253)
    double tBillPrice(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(254)
    double tBillYield(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(255)
    double price(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7);

    @VTID(256)
    double dollarDe(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(257)
    double dollarFr(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(258)
    double nominal(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(259)
    double effect(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(260)
    double cumPrinc(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6);

    @VTID(261)
    double cumIPmt(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6);

    @VTID(262)
    double eDate(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(263)
    double eoMonth(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(264)
    double yearFrac(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(265)
    double coupDayBs(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(266)
    double coupDays(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(267)
    double coupDaysNc(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(268)
    double coupNcd(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(269)
    double coupNum(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(270)
    double coupPcd(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4);

    @VTID(271)
    double duration(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6);

    @VTID(272)
    double mDuration(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6);

    @VTID(273)
    double oddLPrice(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8);

    @VTID(274)
    double oddLYield(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8);

    @VTID(275)
    double oddFPrice(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9);

    @VTID(276)
    double oddFYield(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9);

    @VTID(277)
    double randBetween(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(278)
    double weekNum(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(279)
    double amorDegrc(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7);

    @VTID(280)
    double amorLinc(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7);

    @VTID(281)
    double convert(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(282)
    double accrInt(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7);

    @VTID(283)
    double accrIntM(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5);

    @VTID(284)
    double workDay(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(285)
    double networkDays(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(286)
    double gcd(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(287)
    double multiNomial(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(288)
    double lcm(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(289)
    double fvSchedule(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

    @VTID(290)
    double sumIfs(
        mol.excel.Range arg1,
        mol.excel.Range arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29);

    @VTID(291)
    double countIfs(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg30);

    @VTID(292)
    double averageIf(
        mol.excel.Range arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3);

    @VTID(293)
    double averageIfs(
        mol.excel.Range arg1,
        mol.excel.Range arg2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg5,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg6,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg7,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg8,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg9,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg10,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg11,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg12,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg13,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg14,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg15,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg16,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg17,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg18,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg19,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg20,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg21,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg22,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg23,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg24,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg25,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg26,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg27,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg28,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg29);

    @VTID(294)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object ifError(
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object arg2);

}
