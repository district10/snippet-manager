.PHONY: all clean include

SRC:=$(wildcard index.md */*.md)
DST:=$(addprefix publish/, $(SRC:%.md=%.html))
FROM := markdown+abbreviations
ifeq (,$(DUMB))
	FROM := $(FROM)+east_asian_line_breaks+emoji+raw_tex
endif

all: $(DST) $(CSS)
publish/%/index.html: %/index.md
	@mkdir -p $(@D)
	(perl meta/cat.pl $< | perl meta/drawer.pl || cat $<) | \
	pandoc \
		-V ISINDEX=true \
		-V rootdir=../ \
		-from=markdown+smart \
		-s --ascii --mathjax \
		-f $(FROM) \
		--template meta/note.template \
		-o $@
sitemap:
	touch publish/sitemap.html
	find publish/ | \
		sed -e "s/^publish/-   <http:\/\/tangzx.qiniudn.com\/notes/" | \
		sed -e "s/$$/>/" | tee sitemap.md | \
		pandoc --ascii -o publish/sitemap.html
	cat sitemap.md
