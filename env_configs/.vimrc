call plug#begin('~/.vim/plugged')
Plug 'itchyny/lightline.vim'
Plug 'SirVer/ultisnips'
Plug 'tpope/vim-commentary'
Plug 'cocopon/iceberg.vim'
Plug 'lifepillar/vim-solarized8'
Plug 'jiangmiao/auto-pairs'
Plug 'rhysd/vim-clang-format'
Plug 'kana/vim-operator-user'
Plug 'bfrg/vim-cpp-modern'
Plug 'ycm-core/YouCompleteMe'
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
set ttimeout ttm=0 re=1

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

set cot-=preview
let g:ycm_clangd_args=['--header-insertion=never']
let g:UltiSnipsExpandTrigger = "<NOP>"
let g:UltiSnipsJumpForwardTrigger = "<TAB>"
let g:UltiSnipsJumpBackwardTrigger = "<S-TAB>"
function ExpandSnippet()
    call UltiSnips#ExpandSnippet()
    if g:ulti_expand_res
        return ""
    else
        return "\<CR>"
    endif
endfunction
inoremap <expr> <CR> pumvisible() ? "<C-R>=ExpandSnippet()<CR>" : "\<CR>"
let g:ycm_global_ycm_extra_conf = '~/.vim/plugged/YouCompleteMe/third_party/ycmd/.ycm_extra_conf.py'
