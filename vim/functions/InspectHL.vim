function! InspectHL()

	let l:id = synID(line('.'), col('.'), 1)

	if l:id == 0
		echo 'Syntax: disabled or no syntax group'
	else
		let l:translated = synIDtrans(l:id)
		echo 'Syntax: ' . synIDattr(l:id, 'name') . ' Linked to: ' . synIDattr(l:translated, 'name')
	endif

	for l:m in getmatches()
		echo 'Match group: ' . l:m.group
	endfor

endfunction

command! InspectHL call InspectHL()
