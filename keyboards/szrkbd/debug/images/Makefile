
KEYMAP_C = ../keymap.c

NAMES = $(shell sed -En '/LAYOUT/s/.*\[(.*)\].*/\1/p' $(KEYMAP_C))
SVGS = $(patsubst %,layout-%.svg,$(NAMES))

preview: $(SVGS)
	qlmanage -p index.html

$(SVGS): layout.awk $(KEYMAP_C) layout.css
	awk -f layout.awk $(KEYMAP_C)

clean:
	rm -f $(SVGS) index.html
