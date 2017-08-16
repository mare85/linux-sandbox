set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set colorcolumn=110
highlight ColorColumn ctermbg=8
let &path.="code,/usr/include"
autocmd vimenter * NERDTree
set makeprg=make\ -C\ ./build\ -j9
nnoremap <F3> :!make -C ./build -j9 debug<cr>
nnoremap <F4> :make!<cr>
nnoremap <F5> :!./game<cr>
nnoremap <F6> :!gdbtui ./gameDbg<cr>
nnoremap <F2> :!python ./scripts/addClass.py 
