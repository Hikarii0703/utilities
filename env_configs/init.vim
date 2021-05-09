call plug#begin('~/.vim/plugged')
Plug 'itchyny/lightline.vim'
Plug 'NLKNguyen/papercolor-theme'
Plug 'mengelbrecht/lightline-bufferline'
Plug 'junegunn/limelight.vim'
Plug 'junegunn/goyo.vim'
Plug 'psliwka/vim-smoothie'
Plug 'edkolev/tmuxline.vim'
Plug 'ayu-theme/ayu-vim'

" Plug 'SirVer/ultisnips'
Plug 'tpope/vim-commentary'
Plug 'neoclide/coc.nvim'
Plug 'jackguo380/vim-lsp-cxx-highlight'
Plug 'jiangmiao/auto-pairs'
Plug 'preservim/nerdtree'
" Plug 'Chiel92/vim-autoformat'
" Plug 'cormacrelf/vim-colors-github'
Plug 'skywind3000/asyncrun.vim'
Plug 'junegunn/fzf', { 'do': { -> fzf#install() } }
Plug 'junegunn/fzf.vim'
Plug 'tpope/vim-fugitive'

Plug 'ryanoasis/vim-devicons'
call plug#end()

set tgc t_Co=256 bg=light
let g:solarized_termcolors=256
let ayucolor="light"
colo PaperColor

let g:AutoPairsFlyMode = 0
let g:asyncrun_open = 8
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
      \ },
      \ 'component_raw' : {
      \   'buffers': 1
      \ }
      \ }
let g:lightline#bufferline#clickable = 1
let g:fzf_layout = { 'window': { 'width': 0.9, 'height': 0.9 } }
let $FZF_DEFAULT_OPTS="--ansi --preview-window 'right:60%' --layout reverse --margin=1,4 --preview 'bat --color=always --style=header,grid --line-range :300 {}'"
let $FZF_DEFAULT_COMMAND = 'rg --files --ignore-case --hidden -g "!{.git,node_modules,vendor}/*"'
" command! -bang -nargs=? -complete=dir Files call fzf#vim#files(<q-args>, {'options': ['--layout=reverse', '--info=inline', '--preview', '~/.vim/plugged/fzf.vim/bin/preview.sh {}']}, <bang>0)
command! -bang -nargs=? -complete=dir Files call fzf#vim#files(<q-args>, <bang>0)

set hls is scs
set backspace=indent,eol,start
set sr sw=4 ts=4 et sts=4
set ai si cino=j1,(0,ws,Ws,L0,N-s
set fdm=marker
set ls=2 stal=2 nosmd enc=utf-8 sc nu rnu
set nobk nowb noswf nowrap scl=no mouse=a ruler cul hid
set synmaxcol=2048 cmdheight=2
set clipboard=unnamedplus

function! Bye()
     if len(filter(range(1, bufnr('$')), 'buflisted(v:val)')) == 1
         :q
     else
         :bp | bd #
    endif
endfunction

function! FoldingEnter()
  if &buftype ==# 'quickfix'
    execute "normal! \<CR>"
  else
    execute "cclose"
  endif
endfunction


nmap <C-B> :w <bar> AsyncRun c %<CR>
" nmap <F10> :AsyncRun t<CR>
nn C :%y+<CR>
nn j gj
nn k gk
nn n nzz
nn N Nzz
nn <C-h> <C-w>h
nn <C-j> <C-w>j
nn <C-k> <C-w>k
nn <C-l> <C-w>l
nn <C-F> :Files<CR>
let g:AutoPairsShortcutFastWrap='<C-e>'
nn <silent> <C-n> :NERDTreeToggle<CR>
nn <silent> <C-T> :enew<cr>
nn <silent> <C-W> :call Bye()<CR>
" nn <silent> <A-j> :bprevious<CR>
" nn <silent> <A-k> :bnext<CR>
nn <silent> <S-F> :Buffers<CR>
nn <Leader>ve :e $MYVIMRC<CR>
nn <Leader>vr :source $MYVIMRC<CR>
nn <silent> \ :noh<CR>
nnoremap <silent> <CR> :call FoldingEnter()<CR>
" nn <Leader>fm :Autoformat <bar> w<CR>
cnoreabbrev W execute "w"
cnoreabbrev Q execute "q"

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
au BufNewFile,BufRead * setlocal formatoptions-=cro
au VimLeave *call system("xsel -ib", getreg('+'))
au FileType cpp setlocal commentstring=//\ %s


let g:tmuxline_preset = {
      \'b'    : '#H',
      \'win'  : ['#I', '#W'],
      \'cwin' : ['#I', '#W#F'],
      \'y'    : ['HKR0703']}
