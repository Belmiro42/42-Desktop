cat /etc/passwd | awk '/false/ {print $0}' | awk 'NR % 2 == 1'| cut -f1 -d':' | rev | sort -r | head -n $FT_LINE2 | tail -n $(($FT_LINE2-$FT_LINE1)) | cat | xargs | sed 's/ /, /g; s/$/./'
