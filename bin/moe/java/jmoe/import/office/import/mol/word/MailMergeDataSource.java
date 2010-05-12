package mol.word  ;

import com4j.*;

@IID("{0002091D-0000-0000-C000-000000000046}")
public interface MailMergeDataSource extends Com4jObject {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.lang.String name();

    @VTID(11)
    java.lang.String headerSourceName();

    @VTID(12)
    mol.word.WdMailMergeDataSource type();

    @VTID(13)
    mol.word.WdMailMergeDataSource headerSourceType();

    @VTID(14)
    java.lang.String connectString();

    @VTID(15)
    java.lang.String queryString();

    @VTID(16)
    void queryString(
        java.lang.String prop);

    @VTID(17)
    mol.word.WdMailMergeActiveRecord activeRecord();

    @VTID(18)
    void activeRecord(
        mol.word.WdMailMergeActiveRecord prop);

    @VTID(19)
    int firstRecord();

    @VTID(20)
    void firstRecord(
        int prop);

    @VTID(21)
    int lastRecord();

    @VTID(22)
    void lastRecord(
        int prop);

    @VTID(23)
    mol.word.MailMergeFieldNames fieldNames();

    @VTID(23)
    @ReturnValue(defaultPropertyThrough={mol.word.MailMergeFieldNames.class})
    mol.word.MailMergeFieldName fieldNames(
        java.lang.Object index);

    @VTID(24)
    mol.word.MailMergeDataFields dataFields();

    @VTID(24)
    @ReturnValue(defaultPropertyThrough={mol.word.MailMergeDataFields.class})
    mol.word.MailMergeDataField dataFields(
        java.lang.Object index);

    @VTID(25)
    boolean findRecord2000(
        java.lang.String findText,
        java.lang.String field);

    @VTID(26)
    int recordCount();

    @VTID(27)
    boolean included();

    @VTID(28)
    void included(
        boolean prop);

    @VTID(29)
    boolean invalidAddress();

    @VTID(30)
    void invalidAddress(
        boolean prop);

    @VTID(31)
    java.lang.String invalidComments();

    @VTID(32)
    void invalidComments(
        java.lang.String prop);

    @VTID(33)
    mol.word.MappedDataFields mappedDataFields();

    @VTID(33)
    @ReturnValue(defaultPropertyThrough={mol.word.MappedDataFields.class})
    mol.word.MappedDataField mappedDataFields(
        mol.word.WdMappedDataFields index);

    @VTID(34)
    java.lang.String tableName();

    @VTID(35)
    boolean findRecord(
        java.lang.String findText,
        java.lang.Object field);

    @VTID(36)
    void setAllIncludedFlags(
        boolean included);

    @VTID(37)
    void setAllErrorFlags(
        boolean invalid,
        java.lang.String invalidComment);

    @VTID(38)
    void close();

}
