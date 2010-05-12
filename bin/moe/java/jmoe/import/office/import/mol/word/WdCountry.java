package mol.word  ;

import com4j.*;

public enum WdCountry implements ComEnum {
    wdUS(1),
    wdCanada(2),
    wdLatinAmerica(3),
    wdNetherlands(31),
    wdFrance(33),
    wdSpain(34),
    wdItaly(39),
    wdUK(44),
    wdDenmark(45),
    wdSweden(46),
    wdNorway(47),
    wdGermany(49),
    wdPeru(51),
    wdMexico(52),
    wdArgentina(54),
    wdBrazil(55),
    wdChile(56),
    wdVenezuela(58),
    wdJapan(81),
    wdTaiwan(886),
    wdChina(86),
    wdKorea(82),
    wdFinland(358),
    wdIceland(354),
    ;

    private final int value;
    WdCountry(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
