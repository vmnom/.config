hi clear

hi clear NERDTreeFile
hi NERDTreeFile ctermfg=189

hi Normal ctermfg=60 ctermbg=0 cterm=none
hi StatusLine ctermfg=136 ctermbg=18 cterm=none
hi StatusLineNC ctermfg=gray ctermbg=gray cterm=none

let g:colors_name = "clang"

hi TabLineFill ctermfg=18 ctermbg=11

hi clear Type
hi link Type NERDTreeFile
hi clear PreProc
hi link PreProc Type
hi clear Constant
hi link Constant Type
hi clear LineNr
hi LineNr ctermfg=8
hi clear Comment
hi Comment ctermfg=White
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
