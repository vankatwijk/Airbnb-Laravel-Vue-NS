<template>
  <div class="w-50 m-auto">
    <div class="card card-body">
      <form>
        <div class="form-group">
          <label for="email">E-mail</label>
          <input
            type="text"
            name="email"
            placeholder="Enter your e-mail"
            class="form-control"
            v-model="email"
          />
        </div>

        <div class="form-group">
          <label for="email">Password</label>
          <input
            type="password"
            name="password"
            placeholder="Enter your password"
            class="form-control"
            v-model="password"
          />
        </div>

        <button
          type="submit"
          class="btn btn-primary btn-lg btn-block"
          :disabled="loading"
          @click.prevent="login"
        >Log-in</button>

        <hr />

        <div>
          No account yet?
          <router-link :to="{name: 'register'}" class="font-weight-bold">Register</router-link>
        </div>

        <div>
          Forgotten password?
          <router-link :to="{name: 'home'}" class="font-weight-bold">Reset password</router-link>
        </div>
      </form>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      email: null,
      password: null,
      loading: false
    };
  },
  methods: {

  }
};
</script>