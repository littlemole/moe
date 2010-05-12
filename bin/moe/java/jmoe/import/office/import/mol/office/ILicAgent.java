package mol.office  ;

import com4j.*;

/**
 * ILicAgent Interface
 */
@IID("{00194002-D9C3-11D3-8D59-0050048384E3}")
public interface ILicAgent extends Com4jObject {
    /**
     * method Initialize
     */
    @VTID(7)
    int initialize(
        int dwBPC,
        int dwMode,
        java.lang.String bstrLicSource);

    /**
     * method GetFirstName
     */
    @VTID(8)
    java.lang.String getFirstName();

    /**
     * method SetFirstName
     */
    @VTID(9)
    void setFirstName(
        java.lang.String bstrNewVal);

    /**
     * method GetLastName
     */
    @VTID(10)
    java.lang.String getLastName();

    /**
     * method SetLastName
     */
    @VTID(11)
    void setLastName(
        java.lang.String bstrNewVal);

    /**
     * method GetOrgName
     */
    @VTID(12)
    java.lang.String getOrgName();

    /**
     * method SetOrgName
     */
    @VTID(13)
    void setOrgName(
        java.lang.String bstrNewVal);

    /**
     * method GetEmail
     */
    @VTID(14)
    java.lang.String getEmail();

    /**
     * method SetEmail
     */
    @VTID(15)
    void setEmail(
        java.lang.String bstrNewVal);

    /**
     * method GetPhone
     */
    @VTID(16)
    java.lang.String getPhone();

    /**
     * method SetPhone
     */
    @VTID(17)
    void setPhone(
        java.lang.String bstrNewVal);

    /**
     * method GetAddress1
     */
    @VTID(18)
    java.lang.String getAddress1();

    /**
     * method SetAddress1
     */
    @VTID(19)
    void setAddress1(
        java.lang.String bstrNewVal);

    /**
     * method GetCity
     */
    @VTID(20)
    java.lang.String getCity();

    /**
     * method SetCity
     */
    @VTID(21)
    void setCity(
        java.lang.String bstrNewVal);

    /**
     * method GetState
     */
    @VTID(22)
    java.lang.String getState();

    /**
     * method SetState
     */
    @VTID(23)
    void setState(
        java.lang.String bstrNewVal);

    /**
     * method GetCountryCode
     */
    @VTID(24)
    java.lang.String getCountryCode();

    /**
     * method SetCountryCode
     */
    @VTID(25)
    void setCountryCode(
        java.lang.String bstrNewVal);

    /**
     * method GetCountryDesc
     */
    @VTID(26)
    java.lang.String getCountryDesc();

    /**
     * method SetCountryDesc
     */
    @VTID(27)
    void setCountryDesc(
        java.lang.String bstrNewVal);

    /**
     * method GetZip
     */
    @VTID(28)
    java.lang.String getZip();

    /**
     * method SetZip
     */
    @VTID(29)
    void setZip(
        java.lang.String bstrNewVal);

    /**
     * method GetIsoLanguage
     */
    @VTID(30)
    int getIsoLanguage();

    /**
     * method SetIsoLanguage
     */
    @VTID(31)
    void setIsoLanguage(
        int dwNewVal);

    /**
     * method GetMSUpdate
     */
    @VTID(32)
    java.lang.String getMSUpdate();

    /**
     * method SetMSUpdate
     */
    @VTID(33)
    void setMSUpdate(
        java.lang.String bstrNewVal);

    /**
     * method GetMSOffer
     */
    @VTID(34)
    java.lang.String getMSOffer();

    /**
     * method SetMSOffer
     */
    @VTID(35)
    void setMSOffer(
        java.lang.String bstrNewVal);

    /**
     * method GetOtherOffer
     */
    @VTID(36)
    java.lang.String getOtherOffer();

    /**
     * method SetOtherOffer
     */
    @VTID(37)
    void setOtherOffer(
        java.lang.String bstrNewVal);

    /**
     * method GetAddress2
     */
    @VTID(38)
    java.lang.String getAddress2();

    /**
     * method SetAddress2
     */
    @VTID(39)
    void setAddress2(
        java.lang.String bstrNewVal);

    /**
     * method CheckSystemClock
     */
    @VTID(40)
    int checkSystemClock();

    /**
     * method GetExistingExpiryDate
     */
    @VTID(41)
    java.util.Date getExistingExpiryDate();

    /**
     * method GetNewExpiryDate
     */
    @VTID(42)
    java.util.Date getNewExpiryDate();

    /**
     * method GetBillingFirstName
     */
    @VTID(43)
    java.lang.String getBillingFirstName();

    /**
     * method SetBillingFirstName
     */
    @VTID(44)
    void setBillingFirstName(
        java.lang.String bstrNewVal);

    /**
     * method GetBillingLastName
     */
    @VTID(45)
    java.lang.String getBillingLastName();

    /**
     * method SetBillingLastName
     */
    @VTID(46)
    void setBillingLastName(
        java.lang.String bstrNewVal);

    /**
     * method GetBillingPhone
     */
    @VTID(47)
    java.lang.String getBillingPhone();

    /**
     * method SetBillingPhone
     */
    @VTID(48)
    void setBillingPhone(
        java.lang.String bstrNewVal);

    /**
     * method GetBillingAddress1
     */
    @VTID(49)
    java.lang.String getBillingAddress1();

    /**
     * method SetBillingAddress1
     */
    @VTID(50)
    void setBillingAddress1(
        java.lang.String bstrNewVal);

    /**
     * method GetBillingAddress2
     */
    @VTID(51)
    java.lang.String getBillingAddress2();

    /**
     * method SetBillingAddress2
     */
    @VTID(52)
    void setBillingAddress2(
        java.lang.String bstrNewVal);

    /**
     * method GetBillingCity
     */
    @VTID(53)
    java.lang.String getBillingCity();

    /**
     * method SetBillingCity
     */
    @VTID(54)
    void setBillingCity(
        java.lang.String bstrNewVal);

    /**
     * method GetBillingState
     */
    @VTID(55)
    java.lang.String getBillingState();

    /**
     * method SetBillingState
     */
    @VTID(56)
    void setBillingState(
        java.lang.String bstrNewVal);

    /**
     * method GetBillingCountryCode
     */
    @VTID(57)
    java.lang.String getBillingCountryCode();

    /**
     * method SetBillingCountryCode
     */
    @VTID(58)
    void setBillingCountryCode(
        java.lang.String bstrNewVal);

    /**
     * method GetBillingZip
     */
    @VTID(59)
    java.lang.String getBillingZip();

    /**
     * method SetBillingZip
     */
    @VTID(60)
    void setBillingZip(
        java.lang.String bstrNewVal);

    /**
     * method SaveBillingInfo
     */
    @VTID(61)
    int saveBillingInfo(
        int bSave);

    /**
     * method IsCCRenewalCountry
     */
    @VTID(62)
    int isCCRenewalCountry(
        java.lang.String bstrCountryCode);

    /**
     * method GetVATLabel
     */
    @VTID(63)
    java.lang.String getVATLabel(
        java.lang.String bstrCountryCode);

    /**
     * method GetCCRenewalExpiryDate
     */
    @VTID(64)
    java.util.Date getCCRenewalExpiryDate();

    /**
     * method SetVATNumber
     */
    @VTID(65)
    void setVATNumber(
        java.lang.String bstrVATNumber);

    /**
     * method SetCreditCardType
     */
    @VTID(66)
    void setCreditCardType(
        java.lang.String bstrCCCode);

    /**
     * method SetCreditCardNumber
     */
    @VTID(67)
    void setCreditCardNumber(
        java.lang.String bstrCCNumber);

    /**
     * method SetCreditCardExpiryYear
     */
    @VTID(68)
    void setCreditCardExpiryYear(
        int dwCCYear);

    /**
     * method SetCreditCardExpiryMonth
     */
    @VTID(69)
    void setCreditCardExpiryMonth(
        int dwCCMonth);

    /**
     * method GetCreditCardCount
     */
    @VTID(70)
    int getCreditCardCount();

    /**
     * method GetCreditCardCode
     */
    @VTID(71)
    java.lang.String getCreditCardCode(
        int dwIndex);

    /**
     * method GetCreditCardName
     */
    @VTID(72)
    java.lang.String getCreditCardName(
        int dwIndex);

    /**
     * method GetVATNumber
     */
    @VTID(73)
    java.lang.String getVATNumber();

    /**
     * method GetCreditCardType
     */
    @VTID(74)
    java.lang.String getCreditCardType();

    /**
     * method GetCreditCardNumber
     */
    @VTID(75)
    java.lang.String getCreditCardNumber();

    /**
     * method GetCreditCardExpiryYear
     */
    @VTID(76)
    int getCreditCardExpiryYear();

    /**
     * method GetCreditCardExpiryMonth
     */
    @VTID(77)
    int getCreditCardExpiryMonth();

    /**
     * method GetDisconnectOption
     */
    @VTID(78)
    int getDisconnectOption();

    /**
     * method SetDisconnectOption
     */
    @VTID(79)
    void setDisconnectOption(
        int bNewVal);

    /**
     * method AsyncProcessHandshakeRequest
     */
    @VTID(80)
    void asyncProcessHandshakeRequest(
        int bReviseCustInfo);

    /**
     * method AsyncProcessNewLicenseRequest
     */
    @VTID(81)
    void asyncProcessNewLicenseRequest();

    /**
     * method AsyncProcessReissueLicenseRequest
     */
    @VTID(82)
    void asyncProcessReissueLicenseRequest();

    /**
     * method AsyncProcessRetailRenewalLicenseRequest
     */
    @VTID(83)
    void asyncProcessRetailRenewalLicenseRequest();

    /**
     * method AsyncProcessReviseCustInfoRequest
     */
    @VTID(84)
    void asyncProcessReviseCustInfoRequest();

    /**
     * method AsyncProcessCCRenewalPriceRequest
     */
    @VTID(85)
    void asyncProcessCCRenewalPriceRequest();

    /**
     * method AsyncProcessCCRenewalLicenseRequest
     */
    @VTID(86)
    void asyncProcessCCRenewalLicenseRequest();

    /**
     * method GetAsyncProcessReturnCode
     */
    @VTID(87)
    int getAsyncProcessReturnCode();

    /**
     * method IsUpgradeAvailable
     */
    @VTID(88)
    int isUpgradeAvailable();

    /**
     * method WantUpgrade
     */
    @VTID(89)
    void wantUpgrade(
        int bWantUpgrade);

    /**
     * method AsyncProcessDroppedLicenseRequest
     */
    @VTID(90)
    void asyncProcessDroppedLicenseRequest();

    /**
     * method GenerateInstallationId
     */
    @VTID(91)
    java.lang.String generateInstallationId();

    /**
     * method DepositConfirmationId
     */
    @VTID(92)
    int depositConfirmationId(
        java.lang.String bstrVal);

    /**
     * method VerifyCheckDigits
     */
    @VTID(93)
    int verifyCheckDigits(
        java.lang.String bstrCIDIID);

    /**
     * method GetCurrentExpiryDate
     */
    @VTID(94)
    java.util.Date getCurrentExpiryDate();

    /**
     * method CancelAsyncProcessRequest
     */
    @VTID(95)
    void cancelAsyncProcessRequest(
        int bIsLicenseRequest);

    /**
     * method GetCurrencyDescription
     */
    @VTID(96)
    java.lang.String getCurrencyDescription(
        int dwCurrencyIndex);

    /**
     * method GetPriceItemCount
     */
    @VTID(97)
    int getPriceItemCount();

    /**
     * method GetPriceItemLabel
     */
    @VTID(98)
    java.lang.String getPriceItemLabel(
        int dwIndex);

    /**
     * method GetPriceItemValue
     */
    @VTID(99)
    java.lang.String getPriceItemValue(
        int dwCurrencyIndex,
        int dwIndex);

    /**
     * method GetInvoiceText
     */
    @VTID(100)
    java.lang.String getInvoiceText();

    /**
     * method GetBackendErrorMsg
     */
    @VTID(101)
    java.lang.String getBackendErrorMsg();

    /**
     * method GetCurrencyOption
     */
    @VTID(102)
    int getCurrencyOption();

    /**
     * method SetCurrencyOption
     */
    @VTID(103)
    void setCurrencyOption(
        int dwCurrencyOption);

    /**
     * method GetEndOfLifeHtmlText
     */
    @VTID(104)
    java.lang.String getEndOfLifeHtmlText();

    /**
     * method DisplaySSLCert
     */
    @VTID(105)
    int displaySSLCert();

}
