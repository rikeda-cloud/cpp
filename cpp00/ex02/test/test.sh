#!/bin/bash
DEFAULT_FILE="./test/19920104_091532.log"
RESULT_FILE="./test/result.log"

make && ./dreams > $RESULT_FILE


diff <(awk '{print $2}' "$DEFAULT_FILE") <(awk '{print $2}' "$RESULT_FILE")
