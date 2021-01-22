from django.shortcuts import render
from django.views.generic import (
    ListView, DetailView, CreateView, UpdateView, DeleteView
)
from .models import Post
from django.contrib.auth.mixins import LoginRequiredMixin, UserPassesTestMixin
# from django.http import HttpResponse

#this will come from a database
#---------------Dummy data---------------
# post = [
#     {
#         'author': 'Elusive Nibber',
#         'title': 'Learning Django',
#         'content': 'This is easy but you get lost in a lot of files',
#         'date': 'November 14th Sunday'
#     },
#     {
#         'author': 'Abdullah Raheel',
#         'title': 'Teaching Django',
#         'content': 'This is easy if you are not stupid',
#         'date': 'November 15th Monday'
#     }
# ]
#----------------------------------------

# def home(request):
#     # return HttpResponse('<h1>Django about</h1>')
#     return render(request, 'blog/home.html')


# def home(request):
#     #creating a dictionary to pass into the template
#     context = {
#         'posts' : Post.objects.all()
#         #this key will be accessible from the template
#     }
#     return render(request, 'blog/home.html', context)

class PostListView(ListView):
    model = Post
    template_name = 'blog/home.html' #changes what it looks for
    context_object_name = 'posts'
    ordering = ['-date_posted']    

class PostDetailView(DetailView):
    model = Post

class PostCreateView(LoginRequiredMixin, CreateView):
    model = Post
    fields = ['title', 'content']

    def form_valid(self, form):
        form.instance.author = self.request.user
        return super().form_valid(form)

class PostUpdateView(LoginRequiredMixin, UserPassesTestMixin, UpdateView):
    model = Post
    fields = ['title', 'content']

    def form_valid(self, form):
        form.instance.author = self.request.user
        return super().form_valid(form)
    
    def test_func(self):
        post = self.get_object()
        if self.request.user == post.author:
            return True
        else:
            return False

class PostDeleteView(LoginRequiredMixin, UserPassesTestMixin, DeleteView):
    model = Post
    success_url = '/'
    
    def test_func(self):
        post = self.get_object()
        if self.request.user == post.author:
            return True
        else:
            return False

def about(request):
    # return HttpResponse('<h1>Django about</h1>')
    return render(request, 'blog/about.html', {'title': 'About'})