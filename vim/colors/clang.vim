hi clear

hi Normal ctermfg=189 ctermbg=0 cterm=none
hi StatusLine ctermfg=8 ctermbg=0 cterm=none
hi StatusLineNC ctermfg=0 ctermbg=8 cterm=none,reverse

let g:colors_name = "clang"

hi MatchParen ctermbg=none
hi clear Type
hi Type ctermfg=8
hi clear PreProc
hi link PreProc Type
hi clear Constant
hi link Constant Type
hi clear LineNr
hi link LineNr Type
hi clear Comment
hi Comment ctermfg=239
hi clear Special
hi clear Identifier
hi Identifier ctermfg=32
hi clear Directory 
hi link Directory Normal
hi clear EndOfBuffer
hi link EndOfBuffer NERDTreeFile
hi clear NERDTreeDirSlash
hi NERDTreeDirSlash ctermfg=0 
hi clear VertSplit 
hi link VertSplit Type
hi clear CursorLine
hi clear CursorLineNr
hi clear Statement
hi link Statement Identifier
hi clear NERDTreeFile
hi NERDTreeFile ctermfg=60
hi clear Visual
hi Visual ctermbg=236
hi clear cUserFunction
hi cUserFunction ctermfg=32
