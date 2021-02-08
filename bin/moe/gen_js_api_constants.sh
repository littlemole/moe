#!/bin/bash

awk 'BEGIN{print "var action = { " } { if ($1=="#define" && $3!="") {print $2" : "$3","  }} END { print"};" }' include/resource.h  > resources/deploy/ui/js/action.js
