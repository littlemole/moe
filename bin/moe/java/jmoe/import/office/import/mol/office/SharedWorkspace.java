package mol.office  ;

import com4j.*;

@IID("{000C0385-0000-0000-C000-000000000046}")
public interface SharedWorkspace extends mol.office._IMsoDispObj {
    @VTID(9)
    @DefaultMethod
    java.lang.String name();

    @VTID(10)
    @DefaultMethod
    void name(
        java.lang.String name);

    @VTID(11)
    mol.office.SharedWorkspaceMembers members();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.office.SharedWorkspaceMembers.class})
    mol.office.SharedWorkspaceMember members(
        int index);

    @VTID(12)
    mol.office.SharedWorkspaceTasks tasks();

    @VTID(12)
    @ReturnValue(defaultPropertyThrough={mol.office.SharedWorkspaceTasks.class})
    mol.office.SharedWorkspaceTask tasks(
        int index);

    @VTID(13)
    mol.office.SharedWorkspaceFiles files();

    @VTID(13)
    @ReturnValue(defaultPropertyThrough={mol.office.SharedWorkspaceFiles.class})
    mol.office.SharedWorkspaceFile files(
        int index);

    @VTID(14)
    mol.office.SharedWorkspaceFolders folders();

    @VTID(14)
    @ReturnValue(defaultPropertyThrough={mol.office.SharedWorkspaceFolders.class})
    mol.office.SharedWorkspaceFolder folders(
        int index);

    @VTID(15)
    mol.office.SharedWorkspaceLinks links();

    @VTID(15)
    @ReturnValue(defaultPropertyThrough={mol.office.SharedWorkspaceLinks.class})
    mol.office.SharedWorkspaceLink links(
        int index);

    @VTID(16)
    void refresh();

    @VTID(17)
    void createNew(
        @MarshalAs(NativeType.VARIANT) java.lang.Object url,
        @MarshalAs(NativeType.VARIANT) java.lang.Object name);

    @VTID(18)
    void delete();

    @VTID(19)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(20)
    java.lang.String url();

    @VTID(21)
    boolean connected();

    @VTID(22)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object lastRefreshed();

    @VTID(23)
    java.lang.String sourceURL();

    @VTID(24)
    void sourceURL(
        java.lang.String pbstrSourceURL);

    @VTID(25)
    void removeDocument();

    @VTID(26)
    void disconnect();

}
