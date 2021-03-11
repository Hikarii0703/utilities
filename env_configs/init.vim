call plug#begin('~/.vim/plugged')
Plug 'itchyny/lightline.vim'
Plug 'SirVer/ultisnips'
Plug 'tpope/vim-commentary'
Plug 'cocopon/iceberg.vim'
Plug 'jiangmiao/auto-pairs'
Plug 'neoclide/coc.nvim'
Plug 'Chiel92/vim-autoformat'
Plug 'jackguo380/vim-lsp-cxx-highlight'
Plug 'edkolev/tmuxline.vim'
Plug 'arcticicestudio/nord-vim'
Plug 'preservim/nerdtree'
call plug#end()

set tgc t_Co=256 bg=light
colo iceberg
let ayucolor="light"
let g:lightline={'colorscheme':'iceberg'}
let g:lsp_cxx_hl_light_bg=1
let c_no_curly_error=1

let NERDTreeShowHidden=1
nn <C-F> :NERDTreeToggle<CR>

nn j gj
nn k gk
nn n nzz
nn N Nzz
set hls is scs
nn <C-h> <C-w>h
nn <C-j> <C-w>j
nn <C-k> <C-w>k
nn <C-l> <C-w>l

set sr sw=4 ts=4 et sts=4
set ai si
set fdm=marker fmr=\*INDENT-OFF\*,\*INDENT-ON\* "nofen
set ls=2 nosmd enc=utf-8 sc nu rnu nobk noswf nowrap scl=no mouse=a cul

set clipboard=unnamedplus
au VimLeave *call system("xsel -ib", getreg('+'))
au FileType cpp setlocal commentstring=//\ %s

map <F3> :%y+<CR>
map <F5> :w <bar> !cf submit "https://codeforces.com/contest/""%:p:h:h:t""/problem/""%:t:r"-f "%:t"<CR>

nn <Leader>ve :e $MYVIMRC<CR>
nn <Leader>vr :source $MYVIMRC<CR>
nn <silent> <leader><cr> :noh<cr>

let g:UltiSnipsExpandTrigger="<NOP>"

ino <expr><Tab> pumvisible() ? "\<C-n>" :"\<Tab>"
ino <expr><S-Tab> pumvisible() ? "\<C-p>" :"\<S-Tab>"
ino <silent><expr><cr> pumvisible() ? coc#_select_confirm() :"\<C-g>u\<CR>"

au BufWrite *.cpp :Autoformat

let g:tmuxline_preset = {
      \'b'    : '#H',
      \'win'  : ['#I', '#W'],
      \'cwin' : ['#I', '#W#F'],
      \'y'    : ['HKR0703', '❤', 'PrgrmAnh']}


function! s:CustomizeColors()
    if has('gui_running') || &termguicolors || exists('g:gonvim_running')
        hi CursorLine ctermfg=white
    else
        hi CursorLine guifg=white
    endif
endfunction

augroup OnColorScheme
    au!
    au ColorScheme,BufEnter,BufWinEnter * call s:CustomizeColors()
augroup END

au BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif
au BufEnter * if bufname('#') =~ 'NERD_tree_\d\+' && bufname('%') !~ 'NERD_tree_\d\+' && winnr('$') > 1 | let buf=bufnr() | buffer# | execute "normal! \<C-W>w" | execute 'buffer'.buf | endif
nnoremap <C-n> :NERDTreeMirror<CR>:NERDTreeFocus<CR>