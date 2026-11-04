hi clear NERDTreeFile
hi clear StatusLine
hi clear Identifier
hi clear StatusLineNC
hi clear Directory 
hi clear Type
hi clear cppSTLtype
hi clear PreProc
hi clear Constant
hi clear LineNr
hi clear Comment
hi clear Special
hi clear CursorLine
hi clear VertSplit 
hi clear CursorLineNr
hi clear Statement
hi clear EndOfBuffer
hi clear cUserFunction
hi clear Visual

hi Comment ctermfg=white
hi NERDTreeFile ctermfg=189
hi Normal ctermfg=9 ctermbg=0
hi Visual ctermbg=236
hi Identifier ctermfg=33
hi cStorageClass ctermfg=9
hi CursorLine ctermbg=none cterm=bold

hi MatchParen ctermbg=none
hi StatusLine cterm=none,reverse
hi StatusLineNC cterm=bold,reverse

hi link LineNr Identifier
hi link Special String
hi link PreProc Type
hi link Constant Type
hi link Directory Normal
hi link StatusLine Normal
hi link StatusLineNC Normal
hi link CursorLineNr LineNr
hi link Type NERDTreeFile
hi link EndOfBuffer Normal
hi link Statement Identifier
hi link cUserFunction Identifier
hi link NERDTreeDirSlash Directory
hi link VertSplit Special

set termguicolors
