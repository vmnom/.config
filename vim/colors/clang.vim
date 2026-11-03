hi clear

hi Normal ctermfg=0 ctermbg=gray cterm=none
hi StatusLine ctermfg=gray ctermbg=gray cterm=none
hi StatusLineNC ctermfg=gray ctermbg=gray cterm=none

let g:colors_name = "clang"

hi TabLineFill ctermfg=60
hi TabLineSel ctermfg=white ctermbg=60

hi clear NERDTreeFile
hi NERDTreeFile ctermfg=60
hi clear Type
hi link Type NERDTreeFile
hi clear PreProc
hi link PreProc Type
hi clear Constant
hi link Constant Type
hi clear LineNr
hi LineNr ctermfg=8
hi clear Comment
hi Comment ctermfg=0
hi clear Special
hi link Special StatusLine
hi clear cppSTLtype
hi clear Identifier
hi Identifier ctermfg=25
hi clear Directory 
hi link Directory Normal
hi link NERDTreeDirSlash Directory
hi clear VertSplit 
hi link VertSplit Type
hi clear CursorLine
hi CursorLine ctermbg=none cterm=bold
hi clear CursorLineNr
hi link CursorLineNr Identifier
hi clear Statement
hi link Statement Identifier
hi clear EndOfBuffer
hi clear Visual
hi Visual ctermbg=236
hi clear cUserFunction
hi link cUserFunction Identifier
hi MatchParen ctermbg=none
hi cStorageClass ctermfg=9
