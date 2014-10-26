main_tex=JEREMY_WRIGHT_A4.tex

main_pdf=$(patsubst %.tex,%.pdf,$(main_tex))
tex_files=$(wildcard *.tex)
dot_files=$(wildcard *.dot)
dot_figures=$(patsubst %.dot,%.pdf,$(dot_files))
svg_files=$(wildcard *.svg)
svg_figures=$(patsubst %.svg,%.pdf,$(svg_files))
octave_files=$(wildcard *.m)
octave_figures=$(patsubst %.m,%.tex,$(octave_files))

.SUFFIXES: .png .dot .pdf .tex .txt .dat .svg .m
.PHONY: clean all distclean spell

all: $(main_pdf) 

$(main_pdf): $(main_tex) ../thesis.bib $(tex_files) $(dot_figures) $(svg_figures) $(octave_figures) 

personal.aspell: $(HOME)/.vim/spell/en.utf-8.add
	aspell --lang=en create master ./personal.aspell < ~/dotfiles/vim/spell/en.utf-8.add

spell: $(tex_files) personal.aspell
	$(foreach doc,$(tex_files), aspell --personal personal.aspell --lang=en --mode=tex check $(doc);)

.tex.pdf: 
	latexmk -pdf --halt-on-error $< > compile.log

.pdf.txt:
	ps2txt $< $@

.txt.dat:
	style $< > $@
	
.dot.pdf:
	dot -Tpdf $< > $@

.svg.pdf:
	inkscape --export-area-drawing --export-latex -A$@ $<

.m.tex:
	octave $<

distclean: clean
	rm -rf *.pdf

clean:
	git clean -f


