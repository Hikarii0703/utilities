call plug#begin('~/.vim/plugged')
Plug 'itchyny/lightline.vim'
Plug 'SirVer/ultisnips'
Plug 'tpope/vim-commentary'
Plug 'ayu-theme/ayu-vim'
Plug 'cocopon/iceberg.vim'
call plug#end()

set termguicolors background=light t_Co=256 
syntax on
let g:lightline={'colorscheme': 'iceberg'}
" let ayucolor="dark" 
colo iceberg

nnoremap j gj
nnoremap k gk
nnoremap n nzz
nnoremap N Nzz
set hlsearch incsearch smartcase

set shiftround shiftwidth=4 tabstop=4 expandtab softtabstop=4
set autoindent smartindent cino=j1,(0,ws,Ws,L0
set foldmethod=syntax nofoldenable foldlevel=99 
set laststatus=2 noshowmode encoding=utf-8 showcmd nu rnu nobackup noswapfile nowrap
set ttimeout ttimeoutlen=0

set clipboard=unnamedplus
autocmd VimLeave * call system("xsel -ib", getreg('+'))

autocmd FileType cpp setlocal commentstring=//\ %s

map <leader>fm :%!astyle --mode=c -A14 -xV -H -y -j -xf -p -xg -U -W3<CR>
map <F3> :%y+<CR>
map <F9> :w <bar> !cpcompile "%:t"<CR>
map <F10> :!cf test<CR>
map <F11> :w <bar> !cpcompile "%:t" 11<CR>
map <F12> :w <bar> !cpcompile "%:t" 14<CR>
map <F8> :!cprun "%:t"<CR>
map <F5> :w <bar> !cf submit "https://codeforces.com/contest/""%:p:h:h:t""/problem/""%:t:r" -f "%:t"<CR>
map <F7> :!cf sid
nnoremap <Leader>ve :e $MYVIMRC<CR>
nnoremap <Leader>vr :source $MYVIMRC<CR>
noremap <silent> <leader><cr> :noh<cr>
