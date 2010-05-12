package mol.word  ;

import com4j.*;

@IID("{0002092F-0000-0000-C000-000000000046}")
public interface Field extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    @DefaultMethod
    mol.word.Range code();

    @VTID(11)
    @DefaultMethod
    void code(
        mol.word.Range prop);

    @VTID(12)
    mol.word.WdFieldType type();

    @VTID(13)
    boolean locked();

    @VTID(14)
    void locked(
        boolean prop);

    @VTID(15)
    mol.word.WdFieldKind kind();

    @VTID(16)
    mol.word.Range result();

    @VTID(17)
    void result(
        mol.word.Range prop);

    @VTID(18)
    java.lang.String data();

    @VTID(19)
    void data(
        java.lang.String prop);

    @VTID(20)
    mol.word.Field next();

    @VTID(21)
    mol.word.Field previous();

    @VTID(22)
    int index();

    @VTID(23)
    boolean showCodes();

    @VTID(24)
    void showCodes(
        boolean prop);

    @VTID(25)
    mol.word.LinkFormat linkFormat();

    @VTID(26)
    mol.word.OLEFormat oleFormat();

    @VTID(27)
    mol.word.InlineShape inlineShape();

    @VTID(28)
    void select();

    @VTID(29)
    boolean update();

    @VTID(30)
    void unlink();

    @VTID(31)
    void updateSource();

    @VTID(32)
    void doClick();

    @VTID(33)
    void copy();

    @VTID(34)
    void cut();

    @VTID(35)
    void delete();

}
