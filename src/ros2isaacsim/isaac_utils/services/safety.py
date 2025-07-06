def safe():
    def inner(fun):
        def wrapper(request, response):
            try:
                return fun(request, response)
            except Exception as e:
                print(f"Error in {fun.__name__}: {e}")
                response.ret = False
            return response
        return wrapper
    return inner
