call plug#begin('~/.vim/plugged')
Plug 'itchyny/lightline.vim'
Plug 'SirVer/ultisnips'
Plug 'tpope/vim-commentary'
Plug 'neoclide/coc.nvim'
Plug 'jackguo380/vim-lsp-cxx-highlight'
Plug 'jiangmiao/auto-pairs'
Plug 'preservim/nerdtree'
" Plug 'Chiel92/vim-autoformat'
Plug 'edkolev/tmuxline.vim'
" Plug 'cormacrelf/vim-colors-github'
Plug 'skywind3000/asyncrun.vim'
Plug 'psliwka/vim-smoothie'
" Plug 'ayu-theme/ayu-vim'
Plug 'NLKNguyen/papercolor-theme'
Plug 'mengelbrecht/lightline-bufferline'
call plug#end()

set tgc t_Co=256 bg=light
" let ayucolor="light"
colo PaperColor

let g:AutoPairsFlyMode = 0
let g:asyncrun_open = 8
let g:lightline.component_raw = {'buffers': 1}
let g:lightline#bufferline#clickable = 1
let mapleader = " "
let g:lsp_cxx_hl_light_bg=1
let c_no_curly_error=1
let g:github_colors_soft=0
let NERDTreeShowHidden=1
let g:UltiSnipsExpandTrigger="<NOP>"
let g:lightline = {
      \ 'colorscheme': 'PaperColor',
      \ 'active': {
      \   'left': [ [ 'mode', 'paste' ], [ 'readonly', 'filename', 'modified' ] ]
      \ },
      \ 'tabline': {
      \   'left': [ ['buffers'] ],
      \   'right': [ ['close'] ]
      \ },
      \ 'component_expand': {
      \   'buffers': 'lightline#bufferline#buffers'
      \ },
      \ 'component_type': {
      \   'buffers': 'tabsel'
      \ }
      \ }

set hls is scs
set backspace=indent,eol,start
set sr sw=4 ts=4 et sts=4
set ai si cino=j1,(0,ws,Ws,L0,N-s
set fdm=marker
set ls=2 stal=2 nosmd enc=utf-8 sc nu rnu
set nobk nowb noswf nowrap scl=no mouse=a ruler cul hid
set synmaxcol=2048 cmdheight=2
set clipboard=unnamedplus

au BufNewFile,BufRead * setlocal formatoptions-=cro
au VimLeave *call system("xsel -ib", getreg('+'))
au FileType cpp setlocal commentstring=//\ %s

nmap <C-B> :w <bar> AsyncRun c %<CR>
" nmap <F10> :AsyncRun t<CR>
nnoremap gA :%y+<CR>
nn j gj
nn k gk
nn n nzz
nn N Nzz
nn <C-h> <C-w>h
nn <C-j> <C-w>j
nn <C-k> <C-w>k
nn <C-l> <C-w>l
let g:AutoPairsShortcutFastWrap='<C-e>'
nn <C-n> :NERDTreeToggle<CR>
nmap <C-T> :enew<cr>
nmap tk :bnext<CR>
nmap tj :bprevious<CR>
nmap <C-W> :bp <bar> bd #<CR>
nn <Leader>ve :e $MYVIMRC<CR>
nn <Leader>vr :source $MYVIMRC<CR>
" nn <Leader>fm :Autoformat <bar> w<CR>
nn <silent> <expr> <CR> &buftype ==# 'quickfix' ? "\<CR>" : ":cclose\<CR>"
nn <silent> <Leader><CR> :noh<CR>
vn < <gv
vn > >gv

ino <expr><Tab> pumvisible() ? "\<C-n>" :"\<Tab>"
ino <expr><S-Tab> pumvisible() ? "\<C-p>" :"\<S-Tab>"
ino <silent><expr><cr> pumvisible() ? coc#_select_confirm() :"\<C-g>u\<CR>"
" au BufWrite *.cpp :Autoformat

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

" au BufEnter * if tabpagenr('$') == 1 && winnr('$') == 1 && exists('b:NERDTree') && b:NERDTree.isTabTree() | quit | endif
" au BufEnter * if bufname('#') =~ 'NERD_tree_\d\+' && bufname('%') !~ 'NERD_tree_\d\+' && winnr('$') > 1 | let buf=bufnr() | buffer# | execute "normal! \<C-W>w" | execute 'buffer'.buf | endif

let g:tmuxline_preset = {
      \'b'    : '#H',
      \'win'  : ['#I', '#W'],
      \'cwin' : ['#I', '#W#F'],
      \'y'    : ['HKR0703']}
