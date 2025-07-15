# TODO: group keys by class to rid the class attribute on every rect

BEGIN {
	gridW = 10 # todo: can we determine this from the input?
	gridH = 3  # todo: can we determine this from the input?

	capW = 18 # millimetres
	capH = 18 # millimetres

	# FS = ",[[:space:]]*"
	OFS = ":"

	INDEX = "index.html"
	print "<html>" > INDEX
	print "<style>" >> INDEX
	print "h1 { border-bottom: solid black 1px }" >> INDEX
	print "</style>" >> INDEX
}

END {
	print "</html>" >> INDEX
}

function append_css(file) {
	while((getline line < "layout.css") > 0) {
		print line >> file
	}
	close("layout.css")
}

function key(s) {

	class = substr(s, 1, 2)
	t = ""

	if(1 == index(s, "LT(")) {
		sub(/^LT\(/, "", s)
		sub(/\)$/, "", s)
		split(s, m, ",")
		t = m[1]
		s = m[2]
	}

	if(1 == index(s, "MT(")) {
		sub(/^MT\(/, "", s)
		sub(/\)$/, "", s)
		split(s, m, ",")
		t = m[1]
		s = m[2]
		if(1 == index(t, "MOD_")) {
			t = substr(t, 5)
		}
	}

	if(1 == index(s, "KC_")) { s = substr(s, 4) }
	else if(1 == index(s, "MS_")) { s = substr(s, 4) }
	else if(1 == index(s, "DM_")) { s = substr(s, 4) }
	else if(1 == index(s, "UM_")) { s = substr(s, 4) }
	else if(1 == index(s, "FR_")) { s = substr(s, 4) }
	else if(1 == index(s, "QK_")) { s = substr(s, 4) }
	else if(1 == index(s, "RM_")) { s = substr(s, 4) }
	
	printf("  <g transform='translate(%d, %d)' class='%s'>\n", (.5+x) * capW, (.5+y) * capH, class) >> svg
	printf("    <rect x='%f' y='%f' width='%f' height='%f'/>\n", .05*capW, .05*capH, .9*capW, .9*capH) >> svg
	printf("    <rect x='%f' y='%f' width='%f' height='%f'/>\n", .1*capW, .1*capH, .8*capW, .8*capH) >> svg
	if( "" == t ) {
		printf("    <text x='%f' y='%f'>%s</text>\n", capW/2.0, capH/2.0, s) >> svg
	}
	else {
		printf("    <text x='%f' y='%f'>%s</text>\n", capW/2.0, capH*1.0/3.0, s) >> svg
		printf("    <text x='%f' y='%f'>%s</text>\n", capW/2.0, capH*2.0/3.0, t) >> svg
	}
	print("  </g>") >> svg
	print("") >> svg

	if( ++x >= gridW ) {
		x = 0
		y++
	}
}

/=[[:space:]]*LAYOUT/ {
	split($0, m, /[\[\]]/)
	x = 0
	y = 0
	svg = "layout-" m[2] ".svg"
	print  "Writing " svg
	printf("<h1>%s</h1>", m[2]) >> INDEX
	printf("<img width='800px' src='%s'>\n", svg) >> INDEX

	printf("<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 %d %d'>\n", (1+gridW) * capW, (1+gridH) * capH) > svg
    print ("  <style>") >> svg
	append_css(svg)
	print ("  </style>") >> svg
}
/^[[:space:]]*),$/ && svg!=0 {
	print("</svg>") >> svg
	close(svg)
	svg = 0
}

/(,.*){10,}/ {
	if( 10==NF && 0!=svg ) {
		gsub(/,([[:space:]])/, " ")
		gsub(/,$/, "")

		key($1)
		key($2)
		key($3)
		key($4)
		key($5)
		key($6)
		key($7)
		key($8)
		key($9)
		key($10)
	}
}
