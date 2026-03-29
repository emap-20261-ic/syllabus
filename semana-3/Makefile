
TEX_FILES := $(wildcard *.tex)
PDF_FILES := $(patsubst %.tex,%.pdf,$(TEX_FILES))

.PHONY: all clean

all: $(PDF_FILES)

%.pdf: %.tex
	pdflatex $<
	pdflatex $<

clean:
	rm -f *.aux *.log *.toc *.snm *.vrb *.nav *.out
