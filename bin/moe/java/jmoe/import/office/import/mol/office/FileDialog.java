package mol.office  ;

import com4j.*;

@IID("{000C0362-0000-0000-C000-000000000046}")
public interface FileDialog extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.FileDialogFilters filters();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.office.FileDialogFilters.class})
    mol.office.FileDialogFilter filters(
        int index);

    @VTID(11)
    int filterIndex();

    @VTID(12)
    void filterIndex(
        int filterIndex);

    @VTID(13)
    java.lang.String title();

    @VTID(14)
    void title(
        java.lang.String title);

    @VTID(15)
    java.lang.String buttonName();

    @VTID(16)
    void buttonName(
        java.lang.String buttonName);

    @VTID(17)
    boolean allowMultiSelect();

    @VTID(18)
    void allowMultiSelect(
        boolean pvarfAllowMultiSelect);

    @VTID(19)
    mol.office.MsoFileDialogView initialView();

    @VTID(20)
    void initialView(
        mol.office.MsoFileDialogView pinitialview);

    @VTID(21)
    java.lang.String initialFileName();

    @VTID(22)
    void initialFileName(
        java.lang.String initialFileName);

    @VTID(23)
    mol.office.FileDialogSelectedItems selectedItems();

    @VTID(23)
    @ReturnValue(defaultPropertyThrough={mol.office.FileDialogSelectedItems.class})
    java.lang.String selectedItems(
        int index);

    @VTID(24)
    mol.office.MsoFileDialogType dialogType();

    @VTID(25)
    @DefaultMethod
    java.lang.String item();

    @VTID(26)
    int show();

    @VTID(27)
    void execute();

}
