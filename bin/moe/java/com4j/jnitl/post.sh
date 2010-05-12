#!/bin/zsh -ex
ant clean release
jnupload jnitl "/$(date +%Y-%m-%d) release" "$(date +%Y/%m/%d) release" stable build/jnitl-$(date +%Y%m%d)-win32.zip
