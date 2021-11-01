" Vim color file

set bg=dark
hi clear
if exists("syntax_on")
  syntax reset
endif

let colors_name = "dark"

hi Normal    guifg=#c0c0c0 guibg=#000040        ctermfg=248       ctermbg=black
hi ErrorMsg  guifg=#ffffff guibg=#287eff        ctermfg=white     ctermbg=lightblue
hi Visual    guifg=#8080ff guibg=fg gui=reverse ctermfg=lightblue ctermbg=fg cterm=reverse
hi VisualNOS guifg=#8080ff guibg=fg gui=reverse ctermfg=lightblue ctermbg=fg cterm=reverse,underline
hi Todo      guifg=#d14a14 guibg=#1248d1        ctermfg=red       ctermbg=darkblue
hi Search    guifg=#90fff0 guibg=#2050d0        ctermfg=white     ctermbg=darkblue
hi IncSearch guifg=#b0ffff guibg=#2050d0        ctermfg=darkblue  ctermbg=gray

hi SpecialKey guifg=cyan               ctermfg=darkcyan
hi Directory  guifg=cyan               ctermfg=cyan
hi Title      guifg=magenta gui=none   ctermfg=magenta cterm=bold
hi WarningMsg guifg=red                ctermfg=red
hi WildMenu   guifg=yellow guibg=black ctermfg=yellow ctermbg=black cterm=none term=none
hi ModeMsg    guifg=#22cce2            ctermfg=lightblue
hi MoreMsg                             ctermfg=darkgreen
hi Question   guifg=green gui=none     ctermfg=green cterm=none
hi NonText    guifg=#0030ff            ctermfg=darkblue

hi StatusLine   guifg=blue  guibg=darkgray gui=none ctermfg=blue  ctermbg=gray term=none cterm=none
hi StatusLineNC guifg=black guibg=darkgray gui=none ctermfg=black ctermbg=gray term=none cterm=none
hi VertSplit    guifg=black guibg=darkgray gui=none ctermfg=black ctermbg=gray term=none cterm=none

hi Folded     guifg=#808080 guibg=#000040 ctermfg=darkgrey ctermbg=black cterm=bold term=bold
hi FoldColumn guifg=#808080 guibg=#000040 ctermfg=darkgrey ctermbg=black cterm=bold term=bold
hi LineNr     guifg=#90f020               ctermfg=green                  cterm=none

hi DiffAdd               guibg=darkblue                       ctermbg=darkblue cterm=none term=none
hi DiffChange            guibg=darkmagenta                    ctermbg=magenta  cterm=none
hi DiffDelete guifg=Blue guibg=DarkCyan gui=bold ctermfg=blue ctermbg=cyan
hi DiffText              guibg=Red gui=bold                   ctermbg=red      cterm=bold 

hi Cursor  guifg=black guibg=yellow ctermfg=black ctermbg=yellow
hi lCursor guifg=black guibg=white  ctermfg=black ctermbg=white

hi Comment    guifg=#80a0ff          ctermfg=238
hi Constant   guifg=#ffa0a0          ctermfg=white cterm=none
hi Special    guifg=Orange gui=none  ctermfg=red cterm=none
hi Identifier guifg=#40ffff          ctermfg=cyan cterm=none
hi Statement  guifg=#ffff60 gui=none ctermfg=white cterm=bold
hi PreProc    guifg=#ff80ff gui=none ctermfg=013 cterm=none
hi Type       guifg=#60ff60 gui=none ctermfg=005 cterm=none
hi String     guifg=green   gui=none ctermfg=002 cterm=none
hi Underlined                        cterm=underline term=underline
hi Ignore     guifg=bg               ctermfg=bg

hi Pmenu      guifg=#c0c0c0 guibg=#404080
hi PmenuSel   guifg=#c0c0c0 guibg=#2050d0
hi PmenuSbar  guifg=blue    guibg=darkgray
hi PmenuThumb guifg=#c0c0c0
