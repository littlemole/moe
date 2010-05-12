package mol.word  ;

import com4j.*;

public enum WdPaperTray implements ComEnum {
    wdPrinterDefaultBin(0),
    wdPrinterUpperBin(1),
    wdPrinterOnlyBin(1),
    wdPrinterLowerBin(2),
    wdPrinterMiddleBin(3),
    wdPrinterManualFeed(4),
    wdPrinterEnvelopeFeed(5),
    wdPrinterManualEnvelopeFeed(6),
    wdPrinterAutomaticSheetFeed(7),
    wdPrinterTractorFeed(8),
    wdPrinterSmallFormatBin(9),
    wdPrinterLargeFormatBin(10),
    wdPrinterLargeCapacityBin(11),
    wdPrinterPaperCassette(14),
    wdPrinterFormSource(15),
    ;

    private final int value;
    WdPaperTray(int value) { this.value=value; }
    public int comEnumValue() { return value; }
}
