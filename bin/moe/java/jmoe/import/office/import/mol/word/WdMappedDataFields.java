package mol.word  ;

import com4j.*;

public enum WdMappedDataFields implements ComEnum {
    wdUniqueIdentifier(1),
    wdCourtesyTitle(2),
    wdFirstName(3),
    wdMiddleName(4),
    wdLastName(5),
    wdSuffix(6),
    wdNickname(7),
    wdJobTitle(8),
    wdCompany(9),
    wdAddress1(10),
    wdAddress2(11),
    wdCity(12),
    wdState(13),
    wdPostalCode(14),
    wdCountryRegion(15),
    wdBusinessPhone(16),
    wdBusinessFax(17),
    wdHomePhone(18),
    wdHomeFax(19),
    wdEmailAddress(20),
    wdWebPageURL(21),
    wdSpouseCourtesyTitle(22),
    wdSpouseFirstName(23),
    wdSpouseMiddleName(24),
    wdSpouseLastName(25),
    wdSpouseNickname(26),
    wdRubyFirstName(27),
    wdRubyLastName(28),
    wdAddress3(29),
    wdDepartment(30),
    ;

    private final int value;
    WdMappedDataFields(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
