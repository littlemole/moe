package mol.office  ;

import com4j.*;

@IID("{8A64A872-FC6B-4D4A-926E-3A3689562C1C}")
public interface CustomTaskPaneEvents extends Com4jObject {
    @VTID(7)
    void visibleStateChange(
        mol.office._CustomTaskPane customTaskPaneInst);

    @VTID(8)
    void dockPositionStateChange(
        mol.office._CustomTaskPane customTaskPaneInst);

}
