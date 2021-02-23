call plug#begin('~/.vim/plugged')
Plug 'itchyny/lightline.vim'
Plug 'SirVer/ultisnips'
Plug 'tpope/vim-commentary'
Plug 'cocopon/iceberg.vim'
Plug 'jiangmiao/auto-pairs'
Plug 'rhysd/vim-clang-format'
Plug 'kana/vim-operator-user'
Plug 'bfrg/vim-cpp-modern'
Plug 'neoclide/coc.nvim'
call plug#end()

set termguicolors background=light t_Co=256 
let g:lightline={'colorscheme': 'iceberg'}
colo iceberg
let c_no_curly_error=1
let g:cpp_attributes_highlight = 1
let g:cpp_member_highlight = 1
let g:cpp_simple_highlight = 1

nnoremap j gj
nnoremap k gk
nnoremap n nzz
nnoremap N Nzz
set hlsearch incsearch smartcase

set sr sw=4 ts=4 et sts=4
set ai si cino=j1,(0,ws,Ws,L0
set fdm=marker fmr=clang-format\ off,clang-format\ on
set ls=2 nosmd enc=utf-8 sc nu rnu nobk noswf nowrap cul scl=no mouse=a
set ttimeout ttm=0

set clipboard=unnamedplus
autocmd VimLeave * call system("xsel -ib", getreg('+'))

autocmd FileType cpp setlocal commentstring=//\ %s

let g:clang_format_style = 'file'
let g:clang_format#auto_format=1

map <F2> :!getin<CR>
map <F3> :%y+<CR>
map <F9> :w <bar> !cpcompile "%:t"<CR>
map <F10> :!cf test<CR>
map <F11> :w <bar> !cpcompile "%:t" 11<CR>
map <F12> :w <bar> !cpcompile "%:t" 14<CR>
map <F8> :!cprun "%:t"<CR>
map <F5> :w <bar> !cf submit "https://codeforces.com/contest/""%:p:h:h:t""/problem/""%:t:r" -f "%:t"<CR>
map <F7> :!cprun "%:t" case<CR>
nnoremap <Leader>ve :e $MYVIMRC<CR>
nnoremap <Leader>vr :source $MYVIMRC<CR>
noremap <silent> <leader><cr> :noh<cr>

let g:UltiSnipsExpandTrigger = "<NOP>"

inoremap <expr> <Tab> pumvisible() ? "\<C-n>" : "\<Tab>"
inoremap <expr> <S-Tab> pumvisible() ? "\<C-p>" : "\<S-Tab>"
inoremap <silent><expr> <cr> pumvisible() ? coc#_select_confirm() : "\<C-g>u\<CR>"
