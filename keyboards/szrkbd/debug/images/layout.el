
(defconst convert--footer "</svg>")

(defconst convert--header "<svg xmlns='http://www.w3.org/2000/svg' viewBox='0 0 10 3' width='1200' height='480'>
  <style>
    .key {
      fill: #f0f0f0;
      stroke: #999;
      stroke-width: 0.05;
    }
    .label {
      font-family: monospace;
      font-size: .15px;
      text-anchor: middle;
      dominant-baseline: central;
      fill: #333;
    }
  </style>")

(defconst convert--body "
  <g transform='translate(%d,%d)'>
    <rect class='key' width='1' height='1'/>
    <text class='label' x='0.5' y='0.25'>%s</text>
    <text class='label' x='0.5' y='0.50'>%s</text>
    <text class='label' x='0.5' y='0.75'>%s</text>
  </g>
")

(defun convert--rows (rows y)
  (when rows
	(convert--cols (car rows) y 0)
	(convert--rows (cdr rows) (+ 1 y))))

(defun convert--cols (cols y x)
  (when cols
	(let* (
		   (chunks (split-string (car cols) "[),(]"))
		   (chunks3
			(if (= 1 (length chunks))
				(list "" (car chunks) "")
			  chunks))
		   )
	  (insert (format convert--body x y
					  (nth 0 chunks3)
					  (nth 1 chunks3)
					  (nth 2 chunks3)
					  ))
	  (convert--cols (cdr cols) y (+ 1 x)))))

(defun convert (layout)
  (with-temp-buffer
	(insert convert--header)
	(convert--rows layout 0)
	(insert convert--footer)
	(write-file "layout.svg")
	t))

(let* (
	   (layout
		'(

		  (
		    "KC_Q"                 "KC_W"                 "KC_E"                 "KC_R"                 "KC_T"
		    "KC_Y"                 "KC_U"                 "KC_I"                 "KC_O"                 "KC_P"
		  )

		  (
		    "LT(4,KC_A)"           "LT(1,KC_S)"           "LT(2,KC_D)"           "LT(3,KC_F)"           "KC_G"
		    "KC_H"                 "LT(3,KC_J)"           "LT(2,KC_K)"           "LT(1,KC_L)"           "LT(4,KC_SPC)"
		  )

		  (
		    "MT(MOD_LSFT,KC_Z)"    "MT(MOD_LCTL,KC_X)"    "MT(MOD_LGUI,KC_C)"    "MT(MOD_LALT,KC_V)"    "KC_B"
		    "KC_N"                 "MT(MOD_RALT,KC_M)"    "MT(MOD_RGUI,KC_COMM)" "MT(MOD_RCTL,KC_DOT)"  "KC_RSFT"
		  )

		))
	   )

  (convert layout))
