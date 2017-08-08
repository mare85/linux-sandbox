set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set colorcolumn=110
highlight ColorColumn ctermbg=8
let &path.="code,"
autocmd vimenter * NERDTree
set makeprg=make\ -C\ ./build\ -j9
nnoremap <F4> :make!<cr>
