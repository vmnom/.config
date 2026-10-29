hi clear

hi Normal ctermfg=247 ctermbg=0 cterm=none
hi StatusLine ctermfg=8 ctermbg=0 cterm=none
hi StatusLineNC ctermfg=0 ctermbg=8 cterm=none,reverse

let g:colors_name = "clang"

hi clear NERDTreeFile
hi NERDTreeFile ctermfg=60
hi clear Type
hi link Type NERDTreeFile
hi clear PreProc
hi link PreProc Type
hi clear Constant
hi link Constant Type
hi clear LineNr
hi LineNr ctermfg=189
hi clear Comment
hi Comment ctermfg=239
hi clear Special
hi clear cppSTLtype
hi clear Identifier
hi Identifier ctermfg=8
hi clear Directory 
hi link Directory Normal
hi clear NERDTreeDirSlash
hi NERDTreeDirSlash ctermfg=0 
hi clear VertSplit 
hi link VertSplit Type
hi clear CursorLine
hi CursorLine ctermbg=233 cterm=bold
hi clear CursorLineNr
hi link CursorLineNr Identifier
hi clear Statement
hi link Statement Identifier
hi clear EndOfBuffer
hi link EndOfBuffer StatusLine
hi clear Visual
hi Visual ctermbg=236
hi clear cUserFunction
hi link cUserFunction Identifier
hi MatchParen ctermbg=none
